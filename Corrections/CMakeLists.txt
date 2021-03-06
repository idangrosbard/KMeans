cmake_minimum_required(VERSION 3.17)
project(Corrections C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(includes/cpython)
include_directories(includes/internal)

add_executable(Corrections
        includes/cpython/abstract.h
        includes/cpython/dictobject.h
        includes/cpython/fileobject.h
        includes/cpython/initconfig.h
        includes/cpython/interpreteridobject.h
        includes/cpython/object.h
        includes/cpython/objimpl.h
        includes/cpython/pyerrors.h
        includes/cpython/pylifecycle.h
        includes/cpython/pymem.h
        includes/cpython/pystate.h
        includes/cpython/sysmodule.h
        includes/cpython/traceback.h
        includes/cpython/tupleobject.h
        includes/cpython/unicodeobject.h
        includes/internal/pycore_accu.h
        includes/internal/pycore_atomic.h
        includes/internal/pycore_ceval.h
        includes/internal/pycore_code.h
        includes/internal/pycore_condvar.h
        includes/internal/pycore_context.h
        includes/internal/pycore_fileutils.h
        includes/internal/pycore_getopt.h
        includes/internal/pycore_gil.h
        includes/internal/pycore_hamt.h
        includes/internal/pycore_initconfig.h
        includes/internal/pycore_object.h
        includes/internal/pycore_pathconfig.h
        includes/internal/pycore_pyerrors.h
        includes/internal/pycore_pyhash.h
        includes/internal/pycore_pylifecycle.h
        includes/internal/pycore_pymem.h
        includes/internal/pycore_pystate.h
        includes/internal/pycore_traceback.h
        includes/internal/pycore_tupleobject.h
        includes/internal/pycore_warnings.h
        includes/abstract.h
        includes/asdl.h
        includes/ast.h
        includes/bitset.h
        includes/bltinmodule.h
        includes/boolobject.h
        includes/bytearrayobject.h
        includes/bytes_methods.h
        includes/bytesobject.h
        includes/cellobject.h
        includes/ceval.h
        includes/classobject.h
        includes/code.h
        includes/codecs.h
        includes/compile.h
        includes/complexobject.h
        includes/context.h
        includes/datetime.h
        includes/descrobject.h
        includes/dictobject.h
        includes/dtoa.h
        includes/dynamic_annotations.h
        includes/enumobject.h
        includes/errcode.h
        includes/eval.h
        includes/fileobject.h
        includes/fileutils.h
        includes/floatobject.h
        includes/frameobject.h
        includes/funcobject.h
        includes/genobject.h
        includes/graminit.h
        includes/grammar.h
        includes/import.h
        includes/interpreteridobject.h
        includes/intrcheck.h
        includes/iterobject.h
        includes/listobject.h
        includes/longintrepr.h
        includes/longobject.h
        includes/marshal.h
        includes/memoryobject.h
        includes/methodobject.h
        includes/modsupport.h
        includes/moduleobject.h
        includes/namespaceobject.h
        includes/node.h
        includes/object.h
        includes/objimpl.h
        includes/odictobject.h
        includes/opcode.h
        includes/osdefs.h
        includes/osmodule.h
        includes/parsetok.h
        includes/patchlevel.h
        includes/picklebufobject.h
        includes/py_curses.h
        includes/pyarena.h
        includes/pycapsule.h
        includes/pyconfig.h
        includes/pyctype.h
        includes/pydebug.h
        includes/pydtrace.h
        includes/pyerrors.h
        includes/pyexpat.h
        includes/pyfpe.h
        includes/pyhash.h
        includes/pylifecycle.h
        includes/pymacconfig.h
        includes/pymacro.h
        includes/pymath.h
        includes/pymem.h
        includes/pyport.h
        includes/pystate.h
        includes/pystrcmp.h
        includes/pystrhex.h
        includes/pystrtod.h
        includes/Python-ast.h
        includes/Python.h
        includes/pythonrun.h
        includes/pythread.h
        includes/pytime.h
        includes/rangeobject.h
        includes/setobject.h
        includes/sliceobject.h
        includes/structmember.h
        includes/structseq.h
        includes/symtable.h
        includes/sysmodule.h
        includes/token.h
        includes/traceback.h
        includes/tracemalloc.h
        includes/tupleobject.h
        includes/typeslots.h
        includes/ucnhash.h
        includes/unicodeobject.h
        includes/warnings.h
        includes/weakrefobject.h
        kmeans.c)
