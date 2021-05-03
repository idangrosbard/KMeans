#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define TRUE 1
#define FALSE 0
#define BASE 10
#define MAX_LINE_SIZE 1000
#define DEFAULT_MAX_ITER 100
#define L2_THRESH 0.0

typedef int bool;



/* ---------------LINKED LIST--------------- */
/*
 * A linked list node
 */
typedef struct node {
    struct node * next;
    void* val;
} node;

/*
 * Creating a linked list node, given a pointer to the stored value (value must be on heap)
 */
node* create_node(void* val) {
    node* new_node = malloc(sizeof(node));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

/*
 * A linked list
 */
typedef struct list {
    node * first;
    node * last;
    unsigned long len;
} list;

/*
 * Add val to the end of the list
 */
void add_to_list(list* list, void* val) {
    node* n = create_node(val);
    if (list->len == 0) {
        /* first */
        list->first = n;
        list->last = n;
    } else {
        /* not first */
        list->last->next = n;
        list->last = n;
    }
    list->len += 1;
}

/*
 * Create a linked list
 */
list* create_list() {
    list* l = malloc(sizeof(list));
    l->len = 0;
    l->first = NULL;
    return l;
}

/*
 * A test function to check the list is working properly.
 * OK to delete.
 */
void test_list() {
    list* coordinates_list;
    unsigned long i;
    node* curr;
    unsigned long* num;
    coordinates_list = create_list();
    for (i = 0; i <10; i++) {
        num = malloc(sizeof(unsigned long));
        *num = i;
        add_to_list(coordinates_list, num);
    }
    curr = coordinates_list->first;
    for (i=0; i < coordinates_list->len; i++) {
        num =(unsigned long*)(curr->val);
        printf("%ld\n", *num);
        curr = curr->next;
    }
}

/*
 * Deep copies a list
 */
list* copy_list(list* lst) {
    list* copy;
    node* curr;
    double* val;
    unsigned long iter;
    copy = create_list();
    curr = lst->first;
    for (iter = 0; iter < lst->len; iter++) {
        val = malloc(sizeof(double));
        *val = *((double*)(curr->val));
        add_to_list(copy, val);
        curr = curr->next;
    }

    return copy;
}

/*
 * Creates an empty list of length d
 */
list* create_empty_list(unsigned long d) {
    list* copy;
    double* val;
    unsigned long iter;
    copy = create_list();
    for (iter = 0; iter < d; iter++) {
        val = malloc(sizeof(double));
        *val = 0;
        add_to_list(copy, val);
    }

    return copy;
}

/*
 * Free the list nodes and their values.
 */
void free_list(list* lst, bool free_values) {
    node* curr;
    node* next;
    unsigned long i;
    next = lst->first;

    i = 0;
    for (i = 0; i < lst->len; i++) {
        curr = next;
        if (free_values == TRUE) {
            free(curr->val);
        }
        curr->val = NULL;
        next = curr->next;
        free(curr);
        curr = NULL;
    }
    lst->first=NULL;
    lst->last=NULL;
    lst->len=0;
    free(lst);
}

/*
 * Free all points, and all of their coordinates
 */
void free_points_list(list* points) {
    node* curr;
    node* next;
    unsigned long i;
    next = points->first;

    i = 0;
    for (i = 0; i < points->len; i++) {
        curr = next;
        free_list(curr->val, TRUE);
        curr->val = NULL;
        next = curr->next;
        free(curr);
        curr = NULL;
    }
    points->first=NULL;
    points->last=NULL;
    points->len=0;
    free(points);
}

void free_points_array(list** points, int len) {
    int i;
    for (i = 0; i < len; i++) {
        free_list(points[i], TRUE);
    }

    free(points);
}

/* ---------------READ INPUT--------------- */


list* parse_datapoint(char* datapoint_str) {
    char* start_ptr;
    char* end_ptr;
    double* val;
    list* datapoint;

    start_ptr = datapoint_str;
    end_ptr = start_ptr;

    datapoint = create_list();

    while(*end_ptr != 0) {
        val = calloc(1, sizeof(double));
        *val = strtod(start_ptr, &end_ptr);
        add_to_list(datapoint, val);
        start_ptr = end_ptr+1; /* to ignore the commas */
    }
    

    return datapoint;
}

list* get_datapoints() {
    list* datapoints_list;
    list* datapoint;
    char line[MAX_LINE_SIZE];
    int input_status;
    input_status = 0;
    datapoints_list = create_list();

    input_status = scanf("%s", line);
    
    while(input_status != EOF) {
        datapoint = parse_datapoint(line);
        add_to_list(datapoints_list, datapoint);
        input_status = scanf("%s", line);
    }

    return datapoints_list;
}

/*
 * pointer to the coordinates file, made for the following functions
 */
typedef struct {
    FILE* fp;
    char last_char;
} coordinates_file;

/*
 * Create coordinates file given a filepath
 */
coordinates_file* get_coordinates_file(char* filepath) {
    coordinates_file* file;
    file = malloc(sizeof(coordinates_file));
    file->fp = fopen(filepath, "r+");
    return file;
}

/*
 * Free the coordinates file
 */
void free_coordinates_file(coordinates_file* coordinates_file) {
    fclose(coordinates_file->fp);
    free(coordinates_file);
}

/*
 * Read a single coordinate from the file (between commas)
 */
double* read_coordinate(coordinates_file* file) {
    double* coordinate;
    bool fraction;
    bool negative;
    double divisor;
    coordinate = malloc(sizeof(double));
    *coordinate = 0;
    negative = FALSE;
    fraction = FALSE; 
    divisor = 1;
    while ((file->last_char != EOF) && (file->last_char != ',') && (file->last_char != '\n')) {
        if (file->last_char == '.') {
            fraction = TRUE;
        } else if (file->last_char == '-') {
            negative = TRUE;
        } else if (!fraction) {
            *coordinate *= 10;
            *coordinate += (double)((file->last_char) - '0');
        } else {
            divisor *= 10;
            *coordinate += ((double)((file->last_char) - '0')) / divisor;
        }
        file->last_char = fgetc(file->fp);
    }
    if (negative) {
        *coordinate *= -1;
    }
    return coordinate;
}

/*
 * Read a point (entire line) from a file
 */
list* read_point(coordinates_file* file) {
    list* point;
    point = create_list();
    
    do {
        file->last_char = fgetc(file->fp);
        if (file->last_char == EOF) {
            return NULL;
        }
        add_to_list(point, read_coordinate(file));
    } while ((file->last_char != EOF) && (file->last_char != '\n'));

    return point;
}

/*
 * read all points from given path
 */
list* read_points(char* path_to_datapoints) {
    coordinates_file* file;
    list* datapoints;
    list* point;
    int i;
    datapoints = create_list();
    file = get_coordinates_file(path_to_datapoints);
    i=0;
    while (file->last_char != EOF) {
        i++;
        point = read_point(file);
        if (point != NULL) {
            add_to_list(datapoints, point);
        }
    }
    free_coordinates_file(file);
    return datapoints;
}

void print_point(list* point) {
    node* curr_coordinate;
    double* coordinate;
    unsigned long i;
    curr_coordinate = point->first;
    for (i = 0; i < point->len; i++) {
        coordinate = (double*)(curr_coordinate->val);
        printf("%.4f", *coordinate);
        if (i < point->len - 1) {
            printf(",");
        }
        curr_coordinate = curr_coordinate->next;
    }
}

/*
 * Print a points list
 */
void print_points(list* points) {
    node* curr_point;
    list* point;
    unsigned long i;
    
    curr_point = points->first;
    for (i = 0; i < points->len; i++) {
        point = (list*)(curr_point->val);
        print_point(point);
        curr_point = curr_point->next;
        printf("\n");
    }
}

/* ---------------ALGORITHM--------------- */

void print_kmeans(list** kmeans, int k) {
    int i;

    printf("\n");
    for (i = 0; i < k; i++) {
        print_point(kmeans[i]);
        printf("\n");
    }
}

/*
 * Copies the first K points from 'points' list, as the initial K means
 */
list** initialize_kmeans(list* points, unsigned long k) {
    list** kmeans;
    node* curr;
    list* mean;
    unsigned long i;

    kmeans = malloc(sizeof(list*) * k);
    curr = points->first;

    for (i = 0; i < k; i++) {
        mean = copy_list((list*)(curr->val));
        kmeans[i] = mean;
        curr = curr->next;
    }

    return kmeans;
}

/*
 * Initialize empty k means with d dims each (all values init to zero)
 */
list** initialize_empty_kmeans(unsigned long k, unsigned long d) {
    list** kmeans;
    list* mean;
    unsigned long i;

    kmeans = malloc(sizeof(list*) * k);

    for (i = 0; i < k; i++) {
        mean = create_empty_list(d);
        kmeans[i] = mean;
    }

    return kmeans;
}

/*
 * Calculate l2 squared distance between 2 points
 */
double l2_dist_squared(list* p1, list* p2) {
    node* curr1;
    node* curr2;
    unsigned long iter;
    unsigned long d;
    double dist_squared;
    double val1;
    double val2;
    double delta;

    d = p1->len;
    dist_squared = 0;
    curr1 = p1->first;
    curr2 = p2->first;
    for (iter = 0; iter < d; iter++) {
        val1 = *((double*)(curr1->val));
        val2 = *((double*)(curr2->val));
        delta = val1 - val2;
        dist_squared += delta * delta;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return dist_squared;
}

/*
 * Choose a specific points closest mean
 */
int choose_closest_mean(list* point, list** means, int k) {
    list* curr_mean;
    int closest_mean;
    int iter;
    double min_distance;
    double curr_distance;
    
    min_distance = -1;
    closest_mean = 0;

    for (iter = 0; iter < k; iter++) {
        curr_mean = means[iter];
        curr_distance = l2_dist_squared(point, curr_mean);

        if ((curr_distance < min_distance) || (min_distance < 0)) {
            min_distance = curr_distance;
            closest_mean = iter;
        }
    }
    
    return closest_mean;
}

void update_mean(list* mean, list* point, int denominator, int d) {
    node* point_coordinate;
    node* mean_coordinate;
    int t;
    double val;
    point_coordinate = point->first;
    mean_coordinate = mean->first;
    
    /* Update each coordinate of the mean*/
    for (t = 0; t < d; t++) {
        val = *((double*)(point_coordinate->val));
        val = val / denominator;
        *((double*)(mean_coordinate->val)) += val;
        mean_coordinate = mean_coordinate->next;
        point_coordinate = point_coordinate->next;
    }
}

/*
 * Calcualte the new means based on the assigned points
 */ 
list** calculate_means(list** means, list** assigned_points, int* assigned_counts, int k, int d) {
    int i;
    int j;
    int neighbors_count;
    list** new_means;
    list* curr_mean;
    list* mean_points_list;
    list* curr_point;
    node* curr_point_node;

    new_means = initialize_empty_kmeans((unsigned long)k, (unsigned long)d);

    for (i = 0; i < k; i++) {
        /* if there are new points in the cluster - we retain the old centroid */
        neighbors_count = assigned_counts[i];
        if (neighbors_count == 0) {
            new_means[i] = copy_list(means[i]);
        }
        else {
            curr_mean = new_means[i];
            mean_points_list = assigned_points[i];
            curr_point_node = mean_points_list->first;

            for (j = 0; j < neighbors_count; j++) {
                curr_point = (list*)(curr_point_node->val);
                
                update_mean(curr_mean, curr_point, neighbors_count, d);

                curr_point_node = curr_point_node->next;
            }
        }
    }

    return new_means;
}

/*
 * Assign points the the kmeans, and calculate centroid 
 */
list** calc_k_means_iter(list* data_points, list** means, int k, int N, int d) {
    int i;
    list** new_means;
    list** assigned_points;
    int* assigned_counts;
    int closest_mean_index;
    node* curr_point;

    assigned_points = malloc(sizeof(list*) * k);
    assigned_counts = malloc(sizeof(int) * k);

    for (i = 0; i < k; i++) {
        assigned_points[i] = create_list();
        assigned_counts[i] = 0;
    }
    
    curr_point = data_points->first;
    for (i = 0; i < N; i++) {
        closest_mean_index = choose_closest_mean((list*)(curr_point->val), means, k);
        assigned_counts[closest_mean_index]++;
        add_to_list(assigned_points[closest_mean_index], curr_point->val);
        curr_point = curr_point->next;
    }

    new_means = calculate_means(means, assigned_points, assigned_counts, k, d);

    free(assigned_counts);
    for (i = 0; i < k; i++) {
        free_list(assigned_points[i], FALSE);
    }
    free(assigned_points);

    return new_means;
}

/*
 * Calculate total l2 distance between old k means, and new kmeans;
 */
double calc_multi_point_l2_squared(list** points1, list** points2, int k) {
    double l2_squared;
    int i;
    
    l2_squared = 0;

    for (i = 0; i < k; i++) {
        l2_squared += l2_dist_squared(points1[i], points2[i]);
    }

    return l2_squared;
}

/*
 * Check if the algorithm converged
 */
bool did_converge(list** points1, list** points2, int k, double l2_threshold) {
    double l2_squared;
    l2_squared = calc_multi_point_l2_squared(points1, points2, k);
    if (l2_squared <= (l2_threshold * l2_threshold)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

list** calc_k_means(list* data_points, int k, int N, int d, int max_iter, double l2_threshold) {
    list** former_kmeans;
    list** kmeans;
    int i;
    former_kmeans = initialize_kmeans(data_points, (unsigned long)k);

    for (i = 0; i < max_iter; i++) {
        kmeans = calc_k_means_iter(data_points, former_kmeans, k, N, d);
        if (did_converge(kmeans, former_kmeans, k, l2_threshold)) {
            break;
        }
        free_points_array(former_kmeans, k);
        former_kmeans = kmeans;
    }

    return kmeans;
}





int main(int argc, char** argv) {
    int N;
    int d;
    long k;
    char* end;
    long max_iter;
    list* points;
    list** kmeans;

    max_iter = DEFAULT_MAX_ITER;
    k = strtol(argv[1], &end, BASE);
    assert(k > 0);

    if (argc > 2) {
        max_iter = strtol(argv[2], &end, BASE);
        assert(max_iter > 0);
    }
    
    points = get_datapoints();
    N = (int)(points->len);
    d = (int)(((list*)(points->first->val))->len);

    kmeans = calc_k_means(points, k, N, d, max_iter, L2_THRESH);
    print_kmeans(kmeans, k);

    free_points_list(points);
    free_points_array(kmeans, k);
    
    return 0;
}
