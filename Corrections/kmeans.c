#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
typedef enum type{
    Doubles,
    Points,
    String,
    Lists
}Type;

typedef struct List{
    void* array;
    int max_size;
    int len;
    Type type;
} List;

/********************  Declarations  ***************************/
//Initialize a dynamic list
static List init_list(int max_size, Type type);
//Frees the space allocated to list
static void free_list(List* list);
//copies a given list into another copy with exacts same values
static List copy_list(List* list);
//Appends at the end a given double to a list of doubles
static void append_double(List* list,double number);
//append a given char to end of word
static int size_of_type(Type type);
//Prints the list
static void print_list(List* list);

//Calculate l2 distance between two given points
static double calc_dist(List* point1, List* point2);
//return the index of the closest centroid relative to l2 distance
static int closest_centroid(List* points, List* centroids);
//receive a point, an (temp) centroids array and performs elementwise add.
static void add_vector_to_centroid (List* centroids, int centroid_index, List* point);
/********************  Functions  ***************************/

static int size_of_type(Type type){
    if (type==Doubles){
        return sizeof (double);
    }
    if (type==Points){
        return sizeof(List*);
    }
    if (type==String){
        return sizeof(char);
    }
    if (type==Lists){
        return sizeof(List);
    }
    else{
        return 0;
    }
}

static List init_list(int max_size, Type type){
    List list;
    list.len=0;
    list.max_size = max_size;
    list.array = calloc(max_size,size_of_type(type));
    list.type = type;
    return list;

}

static void free_list(List* list){
    free (list->array);
}

static void append_double(List* list,double number){
    assert(list->type==Doubles);
    double* array_pointer = (double*) list->array;
    if (list->max_size==list->len){
        double* new_array = calloc(list->max_size*2,size_of_type(list->type));
        assert (new_array!=NULL);
        int i;
        for (i=0;i<list->len;i++){
            new_array[i] = array_pointer[i];
        }
        free (list->array);
        list->array = (void*) new_array;
        list->max_size = (list->max_size)*2;
    }
    array_pointer = (double*) list->array;
    array_pointer[list->len]=number;
    list->len= list->len+1;
}



static void append_list(List* list, struct List point){
    assert(list->type==Lists);
    List* array_pointer = (List*) list->array;
    if (list->max_size==list->len){
        List* new_array = calloc(list->max_size*2,size_of_type(list->type));
        assert (new_array!=NULL);
        int i;
        for (i=0;i<list->len;i++){
            new_array[i] = array_pointer[i];
        }
        free (list->array);
        list->array = (void*) new_array;
        list->max_size = (list->max_size)*2;
    }
    array_pointer = (List*) list->array;
    array_pointer[list->len]=point;
    list->len= list->len+1;

}


static void print_list(List* list){
    if (list->len==0){
        return;
    }
    if (list->type==Doubles){
        int i;
        for (i=0;i<(list->len)-1;i++){
            printf("%.4f,", ((double*)list->array)[i]);
        }
        printf ("%.4f\n", ((double*)list->array)[list->len-1]);
    }
    if (list->type==Points){
        List* pointer;
        int i;
        for (i=0; i<list->len;i++){
            pointer = (List*)((List**)list->array)[i];
            print_list(pointer);
        }
    }
    if (list->type==Lists){
        List* pointer;
        int i;
        for (i=0; i<list->len;i++){
            pointer = &((List*)list->array)[i];
            print_list(pointer);
        }
    }
    return;
}

static List copy_list(List* list){
    List new_list;
    new_list.len = list->len;
    new_list.type = list->type;
    new_list.max_size = list->max_size;
    double* array_pointer = (double *)list->array;
    double * temp_array = calloc(list->len,sizeof(double ));
    int i;
    for (i=0; i<list->len;i++){
        temp_array[i] = array_pointer[i];
    }
    new_list.array = temp_array;
    return new_list;
}

static double calc_dist(List* point1, List* point2){
    double sum = 0;
    double* pointer1 = (double*) point1->array;
    double* pointer2 = (double*) point2->array;
    double num1;
    double num2;
    int i;
    for (i=0; i<point1->len;i++){
        num1 = pointer1[i];
        num2 = pointer2[i];
        sum += pow(num1-num2,2);
    }
    return sum;
}

static int closest_centroid(List* point, List* centroids){
    assert(point->type==Doubles);
    int idx = 0;
    List centroid = ((List*)centroids->array)[0];
    double min_dist = calc_dist(point,&centroid);
    double tmp_dst;
    int i;
    for (i=0;i<centroids->len;i++){
        centroid = ((List*)centroids->array)[i];
        tmp_dst= calc_dist(point,&centroid);
        if (tmp_dst<min_dist){
            min_dist = tmp_dst;
            idx = i;
        }
    }
    return idx;
}

static void add_vector_to_centroid (List* centroids, int centroid_index, List* point) {
    List centroid = ((List*) (centroids->array))[centroid_index];
    int i;
    for (i=0; i<point->len;i++){
        ((double*)centroid.array)[i] += ((double*) point->array)[i];
    }
}

static List create_blank_temp_centroids(int k, int d){
    List new_centroids = init_list(k,Lists);
    List point;
    int i;
    int j;
    for (i=0; i<k;i++) {
        point = init_list(d, Doubles);
        for (j = 0; j < d; j++) {
            append_double(&point,0);
        }
        append_list(&new_centroids, point);

    }
    return new_centroids;
}

static int compare_centroids(List* old_centroids, List* new_centroids){
    List centroid1;
    List centroid2;
    double num1=0;
    double num2=0;
    int i;
    int j;
    for (i=0;i<old_centroids->len;i++) {
        centroid1 = ((List *) old_centroids->array)[i];
        centroid2 = ((List*) new_centroids->array)[i];
        for (j=0;j<old_centroids->len;j++){
            num1 = ((double *)centroid1.array)[j];
            num2 = ((double *)centroid2.array)[j];
            if (num1!=num2){
                return 0;
            }
        }
    }
    return 1;
}

/************************ Main ***********************/
static List fit (int k , int max_iter , int d, int n, List* points){
    List centroids = init_list(k,Lists);
    List point;
    int i;
    for (i=0;i<k;i++){
        point = ((List*)(points->array))[i];
        append_list(&centroids,copy_list(&point));
    }
    /** Perform algorithm! **/
    int closest_centroid_idx;
    List temp_centroids = create_blank_temp_centroids(k,d);
    int* count_for_centroid = calloc(k,sizeof(int));
    int iter;
    int point_index;
    int j;
    for (iter=0; iter<max_iter; iter++){
        for (point_index =0; point_index<points->len;point_index++){
            point = ((List*)(points->array))[point_index];
            closest_centroid_idx = closest_centroid(&point, &centroids);
            count_for_centroid[closest_centroid_idx]++ ;
            add_vector_to_centroid(&temp_centroids,closest_centroid_idx,&point);
        }
        for (i=0; i<temp_centroids.len;i++){
            List centroid = ((List*)temp_centroids.array)[i];
            for (j=0;j<centroid.len;j++){
                ((double*) (centroid.array))[j]/= count_for_centroid[i];
            }
        }
        if (compare_centroids(&centroids,&temp_centroids)==1){
            break;
        }
        free_list(&centroids);
        centroids= temp_centroids;
        temp_centroids = create_blank_temp_centroids(k,d);
        free (count_for_centroid);
        count_for_centroid = calloc(k,sizeof(int));
    }

    return centroids;
}



/*
 * This actually defines the geo function using a wrapper C API function
 * The wrapping function needs a PyObject* self argument.
 * This is a requirement for all functions and methods in the C API.
 * It has input PyObject *args from Python.
 */

static List pyList_to_myList(PyObject* data, int n, int d){
    PyObject* point;
    List my_point;
    List my_data = init_list(n,Lists);
    int i;
    int j;
    for (i=0; i<n; i++){
        point =  PyList_GetItem(data ,i);
        my_point = init_list(d,Doubles);
        for (j=0; j<d; j++){
            append_double(&my_point, PyFloat_AsDouble(PyList_GetItem(point,j)));
        }
        append_list(&my_data,my_point);
        my_point = init_list(d,Doubles);
    }
    return my_data;
}

static PyObject* myList_to_Pylist(List* centroids,int k, int d){
    List centroid;
    PyObject* Py_centroids = PyList_New(0);
    PyObject* Py_centroid = PyList_New(0);
    int i;
    int j;
    double num;
    for (i =0; i<k; i++){
        centroid = ((List*)centroids->array)[i];
        for (j=0;j<d;j++){
            num = ((double*)centroid.array)[j];
            PyList_Append(Py_centroid,PyFloat_FromDouble(num));
        }
        PyList_Append(Py_centroids,Py_centroid);
        Py_centroid = PyList_New(0);
    }
    return Py_centroids;
}

static PyObject* kmeans(PyObject *self, PyObject *args){
    int k;
    int max_iter;
    int n;
    int d;
    List centroids;
    PyObject* Pydata;
    /* This parses the Python arguments into a double (d)  variable named z and int (i) variable named n*/
    if(!PyArg_ParseTuple(args, "iiiiO", &k, &max_iter,&n,&d,&Pydata)) {
        return NULL; /* In the CPython API, a NULL value is never valid for a
                        PyObject* so it is used to signal that an error has occurred. */

    }
    else{
        List data = pyList_to_myList(Pydata,n,d);
        centroids = fit(k,max_iter,d,n,&data);

    }
/* This builds the answer ("d" = Convert a C double to a Python floating point number) back into a python object */
    Pydata = myList_to_Pylist(&centroids,k,d);
    return Py_BuildValue("O", Pydata); /*  Py_BuildValue(...) returns a PyObject*  */
}

/*
 * This array tells Python what methods this module has.
 * We will use it in the next structure
 */
static PyMethodDef capiMethods[] = {
    {"fit", (PyCFunction) kmeans, METH_VARARGS, PyDoc_STR("A k-means Algorithm Written in C for Speed!")},
    {NULL, NULL, 0, NULL}

};


/* This initiates the module using the above definitions. */
static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "k_means", /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,  /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    capiMethods /* the PyMethodDef array from before containing the methods of the extension */
};


/*
 * The PyModuleDef structure, in turn, must be passed to the interpreter in the module’s initialization function.
 * The initialization function must be named PyInit_name(), where name is the name of the module and should match
 * what we wrote in struct PyModuleDef.
 * This should be the only non-static item defined in the module file
 */
PyMODINIT_FUNC
PyInit_k_means(void){
    PyObject *m;
    m = PyModule_Create(&moduledef);
    if (!m) {
        return NULL;
    }
    return m;
}