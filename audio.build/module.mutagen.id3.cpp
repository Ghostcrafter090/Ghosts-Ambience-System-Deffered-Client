/* Generated code for Python module 'mutagen.id3'
 * created by Nuitka version 1.5.3
 *
 * This code is in part copyright 2022 Kay Hayen.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "nuitka/prelude.h"

#include "nuitka/unfreezing.h"

#include "__helpers.h"

/* The "module_mutagen$id3" is a Python object pointer of module type.
 *
 * Note: For full compatibility with CPython, every module variable access
 * needs to go through it except for cases where the module cannot possibly
 * have changed in the mean time.
 */

PyObject *module_mutagen$id3;
PyDictObject *moduledict_mutagen$id3;

/* The declarations of module constants used, if any. */
static PyObject *mod_consts[263];
#ifndef __NUITKA_NO_ASSERT__
static Py_hash_t mod_consts_hash[263];
#endif

static PyObject *module_filename_obj = NULL;

/* Indicator if this modules private constants were created yet. */
static bool constants_created = false;

/* Function to create module private constants. */
static void createModuleConstants(void) {
    if (constants_created == false) {
        loadConstantsBlob(&mod_consts[0], UNTRANSLATE("mutagen.id3"));
        constants_created = true;

#ifndef __NUITKA_NO_ASSERT__
        for (int i = 0; i < 263; i++) {
            mod_consts_hash[i] = DEEP_HASH(mod_consts[i]);
        }
#endif
    }
}

// We want to be able to initialize the "__main__" constants in any case.
#if 0
void createMainModuleConstants(void) {
    createModuleConstants();
}
#endif

/* Function to verify module private constants for non-corruption. */
#ifndef __NUITKA_NO_ASSERT__
void checkModuleConstants_mutagen$id3(void) {
    // The module may not have been used at all, then ignore this.
    if (constants_created == false) return;

    for (int i = 0; i < 263; i++) {
        assert(mod_consts_hash[i] == DEEP_HASH(mod_consts[i]));
        CHECK_OBJECT_DEEP(mod_consts[i]);
    }
}
#endif

// The module code objects.
static PyCodeObject *codeobj_84e2103a5ab58db66ba53134f0d612b3;
static PyCodeObject *codeobj_40a23018839a78e0169f1236ebf59485;

static void createModuleCodeObjects(void) {
    module_filename_obj = MAKE_RELATIVE_PATH(mod_consts[259]); CHECK_OBJECT(module_filename_obj);
    codeobj_84e2103a5ab58db66ba53134f0d612b3 = MAKE_CODE_OBJECT(module_filename_obj, 1, 0, mod_consts[260], mod_consts[260], NULL, NULL, 0, 0, 0);
    codeobj_40a23018839a78e0169f1236ebf59485 = MAKE_CODE_OBJECT(module_filename_obj, 88, 0, mod_consts[245], mod_consts[245], mod_consts[261], NULL, 0, 0, 0);
}

// The module function declarations.
NUITKA_CROSS_MODULE PyObject *impl___main__$$$function__4__mro_entries_conversion(PyObject **python_pars);


// The module function definitions.


extern void _initCompiledCellType();
extern void _initCompiledGeneratorType();
extern void _initCompiledFunctionType();
extern void _initCompiledMethodType();
extern void _initCompiledFrameType();

extern PyTypeObject Nuitka_Loader_Type;

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
// Provide a way to create find a function via its C code and create it back
// in another process, useful for multiprocessing extensions like dill
extern void registerDillPluginTables(char const *module_name, PyMethodDef *reduce_compiled_function, PyMethodDef *create_compiled_function);

function_impl_code functable_mutagen$id3[] = {

    NULL
};

static char const *_reduce_compiled_function_argnames[] = {
    "func",
    NULL
};

static PyObject *_reduce_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    PyObject *func;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "O:reduce_compiled_function", (char **)_reduce_compiled_function_argnames, &func, NULL)) {
        return NULL;
    }

    if (Nuitka_Function_Check(func) == false) {
        SET_CURRENT_EXCEPTION_TYPE0_STR(PyExc_TypeError, "not a compiled function");
        return NULL;
    }

    struct Nuitka_FunctionObject *function = (struct Nuitka_FunctionObject *)func;

    function_impl_code *current = functable_mutagen$id3;
    int offset = 0;

    while (*current != NULL) {
        if (*current == function->m_c_code) {
            break;
        }

        current += 1;
        offset += 1;
    }

    if (*current == NULL) {
        SET_CURRENT_EXCEPTION_TYPE0_STR(PyExc_TypeError, "Cannot find compiled function in module.");
        return NULL;
    }

    PyObject *code_object_desc = MAKE_TUPLE_EMPTY(6);
    PyTuple_SET_ITEM0(code_object_desc, 0, function->m_code_object->co_filename);
    PyTuple_SET_ITEM0(code_object_desc, 1, function->m_code_object->co_name);
    PyTuple_SET_ITEM(code_object_desc, 2, PyLong_FromLong(function->m_code_object->co_firstlineno));
    PyTuple_SET_ITEM0(code_object_desc, 3, function->m_code_object->co_varnames);
    PyTuple_SET_ITEM(code_object_desc, 4, PyLong_FromLong(function->m_code_object->co_argcount));
    PyTuple_SET_ITEM(code_object_desc, 5, PyLong_FromLong(function->m_code_object->co_flags));

    CHECK_OBJECT_DEEP(code_object_desc);

    PyObject *result = MAKE_TUPLE_EMPTY(4);
    PyTuple_SET_ITEM(result, 0, PyLong_FromLong(offset));
    PyTuple_SET_ITEM(result, 1, code_object_desc);
    PyTuple_SET_ITEM0(result, 2, function->m_defaults);
    PyTuple_SET_ITEM0(result, 3, function->m_doc != NULL ? function->m_doc : Py_None);

    CHECK_OBJECT_DEEP(result);

    return result;
}

static PyMethodDef _method_def_reduce_compiled_function = {"reduce_compiled_function", (PyCFunction)_reduce_compiled_function,
                                                           METH_VARARGS | METH_KEYWORDS, NULL};

static char const *_create_compiled_function_argnames[] = {
    "func",
    "code_object_desc",
    "defaults",
    "doc",
    NULL
};


static PyObject *_create_compiled_function(PyObject *self, PyObject *args, PyObject *kwds) {
    CHECK_OBJECT_DEEP(args);

    PyObject *func;
    PyObject *code_object_desc;
    PyObject *defaults;
    PyObject *doc;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "OOOO:create_compiled_function", (char **)_create_compiled_function_argnames, &func, &code_object_desc, &defaults, &doc, NULL)) {
        return NULL;
    }

    int offset = PyLong_AsLong(func);

    if (offset == -1 && ERROR_OCCURRED()) {
        return NULL;
    }

    if (offset > sizeof(functable_mutagen$id3) || offset < 0) {
        SET_CURRENT_EXCEPTION_TYPE0_STR(PyExc_TypeError, "Wrong offset for compiled function.");
        return NULL;
    }

    PyObject *filename = PyTuple_GET_ITEM(code_object_desc, 0);
    PyObject *function_name = PyTuple_GET_ITEM(code_object_desc, 1);
    PyObject *line = PyTuple_GET_ITEM(code_object_desc, 2);
    int line_int = PyLong_AsLong(line);
    assert(!ERROR_OCCURRED());

    PyObject *argnames = PyTuple_GET_ITEM(code_object_desc, 3);
    PyObject *arg_count = PyTuple_GET_ITEM(code_object_desc, 4);
    int arg_count_int = PyLong_AsLong(arg_count);
    assert(!ERROR_OCCURRED());
    PyObject *flags = PyTuple_GET_ITEM(code_object_desc, 5);
    int flags_int = PyLong_AsLong(flags);
    assert(!ERROR_OCCURRED());

    PyCodeObject *code_object = MAKE_CODE_OBJECT(
        filename,
        line_int,
        flags_int,
        function_name,
        argnames,
        NULL, // freevars
        arg_count_int,
        0, // TODO: Missing kw_only_count
        0 // TODO: Missing pos_only_count
    );

    struct Nuitka_FunctionObject *result = Nuitka_Function_New(
        functable_mutagen$id3[offset],
        code_object->co_name,
#if PYTHON_VERSION >= 0x300
        NULL, // TODO: Not transferring qualname yet
#endif
        code_object,
        defaults,
#if PYTHON_VERSION >= 0x300
        NULL, // kwdefaults are done on the outside currently
        NULL, // TODO: Not transferring annotations
#endif
        module_mutagen$id3,
        doc,
        NULL,
        0
    );

    return (PyObject *)result;
}

static PyMethodDef _method_def_create_compiled_function = {
    "create_compiled_function",
    (PyCFunction)_create_compiled_function,
    METH_VARARGS | METH_KEYWORDS, NULL
};


#endif

// Internal entry point for module code.
PyObject *modulecode_mutagen$id3(PyObject *module, struct Nuitka_MetaPathBasedLoaderEntry const *loader_entry) {
    // Report entry to PGO.
    PGO_onModuleEntered("mutagen.id3");

    // Store the module for future use.
    module_mutagen$id3 = module;

    // Modules can be loaded again in case of errors, avoid the init being done again.
    static bool init_done = false;

    if (init_done == false) {
#if defined(_NUITKA_MODULE) && 0
        // In case of an extension module loaded into a process, we need to call
        // initialization here because that's the first and potentially only time
        // we are going called.

        // Initialize the constant values used.
        _initBuiltinModule();
        createGlobalConstants();

        /* Initialize the compiled types of Nuitka. */
        _initCompiledCellType();
        _initCompiledGeneratorType();
        _initCompiledFunctionType();
        _initCompiledMethodType();
        _initCompiledFrameType();

        _initSlotCompare();
#if PYTHON_VERSION >= 0x270
        _initSlotIterNext();
#endif

        patchTypeComparison();

        // Enable meta path based loader if not already done.
#ifdef _NUITKA_TRACE
        PRINT_STRING("mutagen.id3: Calling setupMetaPathBasedLoader().\n");
#endif
        setupMetaPathBasedLoader();

#if PYTHON_VERSION >= 0x300
        patchInspectModule();
#endif

#endif

        /* The constants only used by this module are created now. */
#ifdef _NUITKA_TRACE
        PRINT_STRING("mutagen.id3: Calling createModuleConstants().\n");
#endif
        createModuleConstants();

        /* The code objects used by this module are created now. */
#ifdef _NUITKA_TRACE
        PRINT_STRING("mutagen.id3: Calling createModuleCodeObjects().\n");
#endif
        createModuleCodeObjects();

        init_done = true;
    }

    // PRINT_STRING("in initmutagen$id3\n");

    moduledict_mutagen$id3 = MODULE_DICT(module_mutagen$id3);

#ifdef _NUITKA_PLUGIN_DILL_ENABLED
    registerDillPluginTables(loader_entry->name, &_method_def_reduce_compiled_function, &_method_def_create_compiled_function);
#endif

    // Set "__compiled__" to what version information we have.
    UPDATE_STRING_DICT0(
        moduledict_mutagen$id3,
        (Nuitka_StringObject *)const_str_plain___compiled__,
        Nuitka_dunder_compiled_value
    );

    // Update "__package__" value to what it ought to be.
    {
#if 0
        UPDATE_STRING_DICT0(
            moduledict_mutagen$id3,
            (Nuitka_StringObject *)const_str_plain___package__,
            mod_consts[262]
        );
#elif 1
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___name__);

        UPDATE_STRING_DICT0(
            moduledict_mutagen$id3,
            (Nuitka_StringObject *)const_str_plain___package__,
            module_name
        );
#else

#if PYTHON_VERSION < 0x300
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___name__);
        char const *module_name_cstr = PyString_AS_STRING(module_name);

        char const *last_dot = strrchr(module_name_cstr, '.');

        if (last_dot != NULL) {
            UPDATE_STRING_DICT1(
                moduledict_mutagen$id3,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyString_FromStringAndSize(module_name_cstr, last_dot - module_name_cstr)
            );
        }
#else
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___name__);
        Py_ssize_t dot_index = PyUnicode_Find(module_name, const_str_dot, 0, PyUnicode_GetLength(module_name), -1);

        if (dot_index != -1) {
            UPDATE_STRING_DICT1(
                moduledict_mutagen$id3,
                (Nuitka_StringObject *)const_str_plain___package__,
                PyUnicode_Substring(module_name, 0, dot_index)
            );
        }
#endif
#endif
    }

    CHECK_OBJECT(module_mutagen$id3);

    // For deep importing of a module we need to have "__builtins__", so we set
    // it ourselves in the same way than CPython does. Note: This must be done
    // before the frame object is allocated, or else it may fail.

    if (GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___builtins__) == NULL) {
        PyObject *value = (PyObject *)builtin_module;

        // Check if main module, not a dict then but the module itself.
#if defined(_NUITKA_MODULE) || !0
        value = PyModule_GetDict(value);
#endif

        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___builtins__, value);
    }

    UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___loader__, (PyObject *)&Nuitka_Loader_Type);

#if PYTHON_VERSION >= 0x340
// Set the "__spec__" value

#if 0
    // Main modules just get "None" as spec.
    UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___spec__, Py_None);
#else
    // Other modules get a "ModuleSpec" from the standard mechanism.
    {
        PyObject *bootstrap_module = getImportLibBootstrapModule();
        CHECK_OBJECT(bootstrap_module);

        PyObject *_spec_from_module = PyObject_GetAttrString(bootstrap_module, "_spec_from_module");
        CHECK_OBJECT(_spec_from_module);

        PyObject *spec_value = CALL_FUNCTION_WITH_SINGLE_ARG(_spec_from_module, module_mutagen$id3);
        Py_DECREF(_spec_from_module);

        // We can assume this to never fail, or else we are in trouble anyway.
        // CHECK_OBJECT(spec_value);

        if (spec_value == NULL) {
            PyErr_PrintEx(0);
            abort();
        }

// Mark the execution in the "__spec__" value.
        SET_ATTRIBUTE(spec_value, const_str_plain__initializing, Py_True);

        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___spec__, spec_value);
    }
#endif
#endif

    // Temp variables if any
    PyObject *outline_0_var___class__ = NULL;
    PyObject *tmp_assign_unpack_1__assign_source = NULL;
    PyObject *tmp_class_creation_1__bases = NULL;
    PyObject *tmp_class_creation_1__class_decl_dict = NULL;
    PyObject *tmp_class_creation_1__metaclass = NULL;
    PyObject *tmp_class_creation_1__prepared = NULL;
    PyObject *tmp_import_from_1__module = NULL;
    PyObject *tmp_import_from_2__module = NULL;
    PyObject *tmp_import_from_3__module = NULL;
    PyObject *tmp_import_from_4__module = NULL;
    PyObject *tmp_import_from_5__module = NULL;
    PyObject *tmp_import_from_6__module = NULL;
    PyObject *tmp_import_from_7__module = NULL;
    struct Nuitka_FrameObject *frame_84e2103a5ab58db66ba53134f0d612b3;
    NUITKA_MAY_BE_UNUSED char const *type_description_1 = NULL;
    PyObject *exception_type = NULL;
    PyObject *exception_value = NULL;
    PyTracebackObject *exception_tb = NULL;
    NUITKA_MAY_BE_UNUSED int exception_lineno = 0;
    PyObject *tmp_dictset_value;
    PyObject *tmp_dictset_dict;
    PyObject *tmp_dictset_key;
    int tmp_res;
    bool tmp_result;
    PyObject *exception_keeper_type_1;
    PyObject *exception_keeper_value_1;
    PyTracebackObject *exception_keeper_tb_1;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_1;
    PyObject *exception_keeper_type_2;
    PyObject *exception_keeper_value_2;
    PyTracebackObject *exception_keeper_tb_2;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_2;
    PyObject *exception_keeper_type_3;
    PyObject *exception_keeper_value_3;
    PyTracebackObject *exception_keeper_tb_3;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_3;
    PyObject *exception_keeper_type_4;
    PyObject *exception_keeper_value_4;
    PyTracebackObject *exception_keeper_tb_4;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_4;
    PyObject *exception_keeper_type_5;
    PyObject *exception_keeper_value_5;
    PyTracebackObject *exception_keeper_tb_5;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_5;
    PyObject *exception_keeper_type_6;
    PyObject *exception_keeper_value_6;
    PyTracebackObject *exception_keeper_tb_6;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_6;
    PyObject *exception_keeper_type_7;
    PyObject *exception_keeper_value_7;
    PyTracebackObject *exception_keeper_tb_7;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_7;
    NUITKA_MAY_BE_UNUSED nuitka_void tmp_unused;
    PyObject *locals_mutagen$id3$$$class__1__DummySpecForPicard_88 = NULL;
    struct Nuitka_FrameObject *frame_40a23018839a78e0169f1236ebf59485_2;
    NUITKA_MAY_BE_UNUSED char const *type_description_2 = NULL;
    PyObject *exception_keeper_type_8;
    PyObject *exception_keeper_value_8;
    PyTracebackObject *exception_keeper_tb_8;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_8;
    PyObject *exception_keeper_type_9;
    PyObject *exception_keeper_value_9;
    PyTracebackObject *exception_keeper_tb_9;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_9;
    PyObject *exception_keeper_type_10;
    PyObject *exception_keeper_value_10;
    PyTracebackObject *exception_keeper_tb_10;
    NUITKA_MAY_BE_UNUSED int exception_keeper_lineno_10;

    // Module code.
    {
        PyObject *tmp_assign_source_1;
        tmp_assign_source_1 = mod_consts[0];
        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[1], tmp_assign_source_1);
    }
    {
        PyObject *tmp_assign_source_2;
        tmp_assign_source_2 = module_filename_obj;
        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[2], tmp_assign_source_2);
    }
    frame_84e2103a5ab58db66ba53134f0d612b3 = MAKE_MODULE_FRAME(codeobj_84e2103a5ab58db66ba53134f0d612b3, module_mutagen$id3);

    // Push the new frame as the currently active one, and we should be exclusively
    // owning it.
    pushFrameStackCompiledFrame(frame_84e2103a5ab58db66ba53134f0d612b3);
    assert(Py_REFCNT(frame_84e2103a5ab58db66ba53134f0d612b3) == 2);

    // Framed code:
    {
        PyObject *tmp_assign_source_3;
        PyObject *tmp_list_element_1;
        PyObject *tmp_called_value_1;
        PyObject *tmp_expression_value_1;
        PyObject *tmp_args_element_value_1;
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
        {
            PyObject *hard_module = IMPORT_HARD_OS();
            if (likely(hard_module != NULL)) {
                tmp_expression_value_1 = LOOKUP_ATTRIBUTE(hard_module, mod_consts[3]);
            } else {
                tmp_expression_value_1 = NULL;
            }
        }
        if (tmp_expression_value_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
            Py_DECREF(tmp_expression_value_1);

            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_called_value_1 = LOOKUP_ATTRIBUTE(tmp_expression_value_1, mod_consts[4]);
        Py_DECREF(tmp_expression_value_1);
        if (tmp_called_value_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_args_element_value_1 = module_filename_obj;
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
        tmp_list_element_1 = CALL_FUNCTION_WITH_SINGLE_ARG(tmp_called_value_1, tmp_args_element_value_1);
        Py_DECREF(tmp_called_value_1);
        if (tmp_list_element_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_assign_source_3 = MAKE_LIST_EMPTY(3);
        {
            PyObject *tmp_called_value_2;
            PyObject *tmp_expression_value_2;
            PyObject *tmp_args_element_value_2;
            PyObject *tmp_called_value_3;
            PyObject *tmp_expression_value_3;
            PyObject *tmp_args_element_value_3;
            PyObject *tmp_called_value_4;
            PyObject *tmp_expression_value_4;
            PyList_SET_ITEM(tmp_assign_source_3, 0, tmp_list_element_1);
            frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
            {
                PyObject *hard_module = IMPORT_HARD_OS();
                if (likely(hard_module != NULL)) {
                    tmp_expression_value_2 = LOOKUP_ATTRIBUTE(hard_module, mod_consts[3]);
                } else {
                    tmp_expression_value_2 = NULL;
                }
            }
            if (tmp_expression_value_2 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                Py_DECREF(tmp_expression_value_2);

                exception_lineno = 1;

                goto list_build_exception_1;
            }
            tmp_called_value_2 = LOOKUP_ATTRIBUTE(tmp_expression_value_2, mod_consts[5]);
            Py_DECREF(tmp_expression_value_2);
            if (tmp_called_value_2 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 1;

                goto list_build_exception_1;
            }
            frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
            {
                PyObject *hard_module = IMPORT_HARD_OS();
                if (likely(hard_module != NULL)) {
                    tmp_expression_value_3 = LOOKUP_ATTRIBUTE(hard_module, mod_consts[6]);
                } else {
                    tmp_expression_value_3 = NULL;
                }
            }
            if (tmp_expression_value_3 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                Py_DECREF(tmp_called_value_2);
                Py_DECREF(tmp_expression_value_3);

                exception_lineno = 1;

                goto list_build_exception_1;
            }
            tmp_called_value_3 = LOOKUP_ATTRIBUTE(tmp_expression_value_3, mod_consts[7]);
            Py_DECREF(tmp_expression_value_3);
            if (tmp_called_value_3 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                Py_DECREF(tmp_called_value_2);

                exception_lineno = 1;

                goto list_build_exception_1;
            }
            frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
            tmp_args_element_value_2 = CALL_FUNCTION_WITH_POSARGS2(tmp_called_value_3, mod_consts[8]);

            Py_DECREF(tmp_called_value_3);
            if (tmp_args_element_value_2 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                Py_DECREF(tmp_called_value_2);

                exception_lineno = 1;

                goto list_build_exception_1;
            }
            tmp_args_element_value_3 = mod_consts[9];
            frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
            {
                PyObject *call_args[] = {tmp_args_element_value_2, tmp_args_element_value_3};
                tmp_list_element_1 = CALL_FUNCTION_WITH_ARGS2(tmp_called_value_2, call_args);
            }

            Py_DECREF(tmp_called_value_2);
            Py_DECREF(tmp_args_element_value_2);
            if (tmp_list_element_1 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 1;

                goto list_build_exception_1;
            }
            PyList_SET_ITEM(tmp_assign_source_3, 1, tmp_list_element_1);
            frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
            {
                PyObject *hard_module = IMPORT_HARD_OS();
                if (likely(hard_module != NULL)) {
                    tmp_expression_value_4 = LOOKUP_ATTRIBUTE(hard_module, mod_consts[6]);
                } else {
                    tmp_expression_value_4 = NULL;
                }
            }
            if (tmp_expression_value_4 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);
                Py_DECREF(tmp_expression_value_4);

                exception_lineno = 1;

                goto list_build_exception_1;
            }
            tmp_called_value_4 = LOOKUP_ATTRIBUTE(tmp_expression_value_4, mod_consts[7]);
            Py_DECREF(tmp_expression_value_4);
            if (tmp_called_value_4 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 1;

                goto list_build_exception_1;
            }
            frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 1;
            tmp_list_element_1 = CALL_FUNCTION_WITH_POSARGS2(tmp_called_value_4, mod_consts[10]);

            Py_DECREF(tmp_called_value_4);
            if (tmp_list_element_1 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 1;

                goto list_build_exception_1;
            }
            PyList_SET_ITEM(tmp_assign_source_3, 2, tmp_list_element_1);
        }
        goto list_build_noexception_1;
        // Exception handling pass through code for list_build:
        list_build_exception_1:;
        Py_DECREF(tmp_assign_source_3);
        goto frame_exception_exit_1;
        // Finished with no exception for list_build:
        list_build_noexception_1:;
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[11], tmp_assign_source_3);
    }
    {
        PyObject *tmp_expression_value_5;
        PyObject *tmp_subscript_value_1;
        tmp_dictset_value = Nuitka_Loader_New(loader_entry);
        tmp_dictset_dict = Nuitka_SysGetObject("path_importer_cache");
        if (tmp_dictset_dict == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_expression_value_5 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[11]);

        if (unlikely(tmp_expression_value_5 == NULL)) {
            tmp_expression_value_5 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[11]);
        }

        assert(!(tmp_expression_value_5 == NULL));
        tmp_subscript_value_1 = mod_consts[12];
        tmp_dictset_key = LOOKUP_SUBSCRIPT_CONST(tmp_expression_value_5, tmp_subscript_value_1, 0);
        if (tmp_dictset_key == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        assert(PyDict_CheckExact(tmp_dictset_dict));
        tmp_res = PyDict_SetItem(tmp_dictset_dict, tmp_dictset_key, tmp_dictset_value);

        Py_DECREF(tmp_dictset_key);
        if (tmp_res != 0) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assattr_value_1;
        PyObject *tmp_assattr_target_1;
        tmp_assattr_value_1 = module_filename_obj;
        tmp_assattr_target_1 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[13]);

        if (unlikely(tmp_assattr_target_1 == NULL)) {
            tmp_assattr_target_1 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[13]);
        }

        assert(!(tmp_assattr_target_1 == NULL));
        tmp_result = SET_ATTRIBUTE(tmp_assattr_target_1, mod_consts[14], tmp_assattr_value_1);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assattr_value_2;
        PyObject *tmp_assattr_target_2;
        tmp_assattr_value_2 = Py_True;
        tmp_assattr_target_2 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[13]);

        if (unlikely(tmp_assattr_target_2 == NULL)) {
            tmp_assattr_target_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[13]);
        }

        assert(!(tmp_assattr_target_2 == NULL));
        tmp_result = SET_ATTRIBUTE(tmp_assattr_target_2, mod_consts[15], tmp_assattr_value_2);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assattr_value_3;
        PyObject *tmp_assattr_target_3;
        tmp_assattr_value_3 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[11]);

        if (unlikely(tmp_assattr_value_3 == NULL)) {
            tmp_assattr_value_3 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[11]);
        }

        if (tmp_assattr_value_3 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
        tmp_assattr_target_3 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[13]);

        if (unlikely(tmp_assattr_target_3 == NULL)) {
            tmp_assattr_target_3 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[13]);
        }

        assert(!(tmp_assattr_target_3 == NULL));
        tmp_result = SET_ATTRIBUTE(tmp_assattr_target_3, mod_consts[16], tmp_assattr_value_3);
        if (tmp_result == false) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 1;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_assign_source_4;
        tmp_assign_source_4 = Py_None;
        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[17], tmp_assign_source_4);
    }
    {
        PyObject *tmp_assign_source_5;
        PyObject *tmp_name_value_1;
        PyObject *tmp_globals_arg_value_1;
        PyObject *tmp_locals_arg_value_1;
        PyObject *tmp_fromlist_value_1;
        PyObject *tmp_level_value_1;
        tmp_name_value_1 = mod_consts[18];
        tmp_globals_arg_value_1 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_1 = Py_None;
        tmp_fromlist_value_1 = mod_consts[19];
        tmp_level_value_1 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 32;
        tmp_assign_source_5 = IMPORT_MODULE5(tmp_name_value_1, tmp_globals_arg_value_1, tmp_locals_arg_value_1, tmp_fromlist_value_1, tmp_level_value_1);
        if (tmp_assign_source_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 32;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_1__module == NULL);
        tmp_import_from_1__module = tmp_assign_source_5;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_6;
        PyObject *tmp_import_name_from_1;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_1 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_1)) {
            tmp_assign_source_6 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_1,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[21],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_6 = IMPORT_NAME(tmp_import_name_from_1, mod_consts[21]);
        }

        if (tmp_assign_source_6 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 32;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[21], tmp_assign_source_6);
    }
    {
        PyObject *tmp_assign_source_7;
        PyObject *tmp_import_name_from_2;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_2 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_2)) {
            tmp_assign_source_7 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_2,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[22],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_7 = IMPORT_NAME(tmp_import_name_from_2, mod_consts[22]);
        }

        if (tmp_assign_source_7 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 32;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[22], tmp_assign_source_7);
    }
    {
        PyObject *tmp_assign_source_8;
        PyObject *tmp_import_name_from_3;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_3 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_3)) {
            tmp_assign_source_8 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_3,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[23],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_8 = IMPORT_NAME(tmp_import_name_from_3, mod_consts[23]);
        }

        if (tmp_assign_source_8 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 32;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[23], tmp_assign_source_8);
    }
    {
        PyObject *tmp_assign_source_9;
        PyObject *tmp_import_name_from_4;
        CHECK_OBJECT(tmp_import_from_1__module);
        tmp_import_name_from_4 = tmp_import_from_1__module;
        if (PyModule_Check(tmp_import_name_from_4)) {
            tmp_assign_source_9 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_4,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[24],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_9 = IMPORT_NAME(tmp_import_name_from_4, mod_consts[24]);
        }

        if (tmp_assign_source_9 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 32;

            goto try_except_handler_1;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[24], tmp_assign_source_9);
    }
    goto try_end_1;
    // Exception handler code:
    try_except_handler_1:;
    exception_keeper_type_1 = exception_type;
    exception_keeper_value_1 = exception_value;
    exception_keeper_tb_1 = exception_tb;
    exception_keeper_lineno_1 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_1__module);
    Py_DECREF(tmp_import_from_1__module);
    tmp_import_from_1__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_1;
    exception_value = exception_keeper_value_1;
    exception_tb = exception_keeper_tb_1;
    exception_lineno = exception_keeper_lineno_1;

    goto frame_exception_exit_1;
    // End of try:
    try_end_1:;
    CHECK_OBJECT(tmp_import_from_1__module);
    Py_DECREF(tmp_import_from_1__module);
    tmp_import_from_1__module = NULL;
    {
        PyObject *tmp_assign_source_10;
        PyObject *tmp_name_value_2;
        PyObject *tmp_globals_arg_value_2;
        PyObject *tmp_locals_arg_value_2;
        PyObject *tmp_fromlist_value_2;
        PyObject *tmp_level_value_2;
        tmp_name_value_2 = mod_consts[25];
        tmp_globals_arg_value_2 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_2 = Py_None;
        tmp_fromlist_value_2 = mod_consts[26];
        tmp_level_value_2 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 33;
        tmp_assign_source_10 = IMPORT_MODULE5(tmp_name_value_2, tmp_globals_arg_value_2, tmp_locals_arg_value_2, tmp_fromlist_value_2, tmp_level_value_2);
        if (tmp_assign_source_10 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 33;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_2__module == NULL);
        tmp_import_from_2__module = tmp_assign_source_10;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_11;
        PyObject *tmp_import_name_from_5;
        CHECK_OBJECT(tmp_import_from_2__module);
        tmp_import_name_from_5 = tmp_import_from_2__module;
        if (PyModule_Check(tmp_import_name_from_5)) {
            tmp_assign_source_11 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_5,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[27],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_11 = IMPORT_NAME(tmp_import_name_from_5, mod_consts[27]);
        }

        if (tmp_assign_source_11 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 33;

            goto try_except_handler_2;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[27], tmp_assign_source_11);
    }
    {
        PyObject *tmp_assign_source_12;
        PyObject *tmp_import_name_from_6;
        CHECK_OBJECT(tmp_import_from_2__module);
        tmp_import_name_from_6 = tmp_import_from_2__module;
        if (PyModule_Check(tmp_import_name_from_6)) {
            tmp_assign_source_12 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_6,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[28],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_12 = IMPORT_NAME(tmp_import_name_from_6, mod_consts[28]);
        }

        if (tmp_assign_source_12 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 33;

            goto try_except_handler_2;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[28], tmp_assign_source_12);
    }
    {
        PyObject *tmp_assign_source_13;
        PyObject *tmp_import_name_from_7;
        CHECK_OBJECT(tmp_import_from_2__module);
        tmp_import_name_from_7 = tmp_import_from_2__module;
        if (PyModule_Check(tmp_import_name_from_7)) {
            tmp_assign_source_13 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_7,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[29],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_13 = IMPORT_NAME(tmp_import_name_from_7, mod_consts[29]);
        }

        if (tmp_assign_source_13 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 33;

            goto try_except_handler_2;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[29], tmp_assign_source_13);
    }
    {
        PyObject *tmp_assign_source_14;
        PyObject *tmp_import_name_from_8;
        CHECK_OBJECT(tmp_import_from_2__module);
        tmp_import_name_from_8 = tmp_import_from_2__module;
        if (PyModule_Check(tmp_import_name_from_8)) {
            tmp_assign_source_14 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_8,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[30],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_14 = IMPORT_NAME(tmp_import_name_from_8, mod_consts[30]);
        }

        if (tmp_assign_source_14 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 33;

            goto try_except_handler_2;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[30], tmp_assign_source_14);
    }
    goto try_end_2;
    // Exception handler code:
    try_except_handler_2:;
    exception_keeper_type_2 = exception_type;
    exception_keeper_value_2 = exception_value;
    exception_keeper_tb_2 = exception_tb;
    exception_keeper_lineno_2 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_2__module);
    Py_DECREF(tmp_import_from_2__module);
    tmp_import_from_2__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_2;
    exception_value = exception_keeper_value_2;
    exception_tb = exception_keeper_tb_2;
    exception_lineno = exception_keeper_lineno_2;

    goto frame_exception_exit_1;
    // End of try:
    try_end_2:;
    CHECK_OBJECT(tmp_import_from_2__module);
    Py_DECREF(tmp_import_from_2__module);
    tmp_import_from_2__module = NULL;
    {
        PyObject *tmp_assign_source_15;
        PyObject *tmp_name_value_3;
        PyObject *tmp_globals_arg_value_3;
        PyObject *tmp_locals_arg_value_3;
        PyObject *tmp_fromlist_value_3;
        PyObject *tmp_level_value_3;
        tmp_name_value_3 = mod_consts[31];
        tmp_globals_arg_value_3 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_3 = Py_None;
        tmp_fromlist_value_3 = mod_consts[32];
        tmp_level_value_3 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 34;
        tmp_assign_source_15 = IMPORT_MODULE5(tmp_name_value_3, tmp_globals_arg_value_3, tmp_locals_arg_value_3, tmp_fromlist_value_3, tmp_level_value_3);
        if (tmp_assign_source_15 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_3__module == NULL);
        tmp_import_from_3__module = tmp_assign_source_15;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_16;
        PyObject *tmp_import_name_from_9;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_9 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_9)) {
            tmp_assign_source_16 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_9,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[33],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_16 = IMPORT_NAME(tmp_import_name_from_9, mod_consts[33]);
        }

        if (tmp_assign_source_16 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[33], tmp_assign_source_16);
    }
    {
        PyObject *tmp_assign_source_17;
        PyObject *tmp_import_name_from_10;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_10 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_10)) {
            tmp_assign_source_17 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_10,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[34],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_17 = IMPORT_NAME(tmp_import_name_from_10, mod_consts[34]);
        }

        if (tmp_assign_source_17 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[34], tmp_assign_source_17);
    }
    {
        PyObject *tmp_assign_source_18;
        PyObject *tmp_import_name_from_11;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_11 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_11)) {
            tmp_assign_source_18 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_11,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[35],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_18 = IMPORT_NAME(tmp_import_name_from_11, mod_consts[35]);
        }

        if (tmp_assign_source_18 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[35], tmp_assign_source_18);
    }
    {
        PyObject *tmp_assign_source_19;
        PyObject *tmp_import_name_from_12;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_12 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_12)) {
            tmp_assign_source_19 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_12,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[36],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_19 = IMPORT_NAME(tmp_import_name_from_12, mod_consts[36]);
        }

        if (tmp_assign_source_19 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[36], tmp_assign_source_19);
    }
    {
        PyObject *tmp_assign_source_20;
        PyObject *tmp_import_name_from_13;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_13 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_13)) {
            tmp_assign_source_20 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_13,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[37],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_20 = IMPORT_NAME(tmp_import_name_from_13, mod_consts[37]);
        }

        if (tmp_assign_source_20 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[37], tmp_assign_source_20);
    }
    {
        PyObject *tmp_assign_source_21;
        PyObject *tmp_import_name_from_14;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_14 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_14)) {
            tmp_assign_source_21 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_14,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[38],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_21 = IMPORT_NAME(tmp_import_name_from_14, mod_consts[38]);
        }

        if (tmp_assign_source_21 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[38], tmp_assign_source_21);
    }
    {
        PyObject *tmp_assign_source_22;
        PyObject *tmp_import_name_from_15;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_15 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_15)) {
            tmp_assign_source_22 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_15,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[39],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_22 = IMPORT_NAME(tmp_import_name_from_15, mod_consts[39]);
        }

        if (tmp_assign_source_22 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[39], tmp_assign_source_22);
    }
    {
        PyObject *tmp_assign_source_23;
        PyObject *tmp_import_name_from_16;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_16 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_16)) {
            tmp_assign_source_23 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_16,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[40],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_23 = IMPORT_NAME(tmp_import_name_from_16, mod_consts[40]);
        }

        if (tmp_assign_source_23 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[40], tmp_assign_source_23);
    }
    {
        PyObject *tmp_assign_source_24;
        PyObject *tmp_import_name_from_17;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_17 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_17)) {
            tmp_assign_source_24 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_17,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[41],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_24 = IMPORT_NAME(tmp_import_name_from_17, mod_consts[41]);
        }

        if (tmp_assign_source_24 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[41], tmp_assign_source_24);
    }
    {
        PyObject *tmp_assign_source_25;
        PyObject *tmp_import_name_from_18;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_18 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_18)) {
            tmp_assign_source_25 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_18,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[42],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_25 = IMPORT_NAME(tmp_import_name_from_18, mod_consts[42]);
        }

        if (tmp_assign_source_25 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[42], tmp_assign_source_25);
    }
    {
        PyObject *tmp_assign_source_26;
        PyObject *tmp_import_name_from_19;
        CHECK_OBJECT(tmp_import_from_3__module);
        tmp_import_name_from_19 = tmp_import_from_3__module;
        if (PyModule_Check(tmp_import_name_from_19)) {
            tmp_assign_source_26 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_19,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[43],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_26 = IMPORT_NAME(tmp_import_name_from_19, mod_consts[43]);
        }

        if (tmp_assign_source_26 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 34;

            goto try_except_handler_3;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[43], tmp_assign_source_26);
    }
    goto try_end_3;
    // Exception handler code:
    try_except_handler_3:;
    exception_keeper_type_3 = exception_type;
    exception_keeper_value_3 = exception_value;
    exception_keeper_tb_3 = exception_tb;
    exception_keeper_lineno_3 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_3__module);
    Py_DECREF(tmp_import_from_3__module);
    tmp_import_from_3__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_3;
    exception_value = exception_keeper_value_3;
    exception_tb = exception_keeper_tb_3;
    exception_lineno = exception_keeper_lineno_3;

    goto frame_exception_exit_1;
    // End of try:
    try_end_3:;
    CHECK_OBJECT(tmp_import_from_3__module);
    Py_DECREF(tmp_import_from_3__module);
    tmp_import_from_3__module = NULL;
    {
        PyObject *tmp_assign_source_27;
        PyObject *tmp_name_value_4;
        PyObject *tmp_globals_arg_value_4;
        PyObject *tmp_locals_arg_value_4;
        PyObject *tmp_fromlist_value_4;
        PyObject *tmp_level_value_4;
        tmp_name_value_4 = mod_consts[44];
        tmp_globals_arg_value_4 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_4 = Py_None;
        tmp_fromlist_value_4 = mod_consts[45];
        tmp_level_value_4 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 37;
        tmp_assign_source_27 = IMPORT_MODULE5(tmp_name_value_4, tmp_globals_arg_value_4, tmp_locals_arg_value_4, tmp_fromlist_value_4, tmp_level_value_4);
        if (tmp_assign_source_27 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_4__module == NULL);
        tmp_import_from_4__module = tmp_assign_source_27;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_28;
        PyObject *tmp_import_name_from_20;
        CHECK_OBJECT(tmp_import_from_4__module);
        tmp_import_name_from_20 = tmp_import_from_4__module;
        if (PyModule_Check(tmp_import_name_from_20)) {
            tmp_assign_source_28 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_20,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[46],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_28 = IMPORT_NAME(tmp_import_name_from_20, mod_consts[46]);
        }

        if (tmp_assign_source_28 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_4;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[46], tmp_assign_source_28);
    }
    {
        PyObject *tmp_assign_source_29;
        PyObject *tmp_import_name_from_21;
        CHECK_OBJECT(tmp_import_from_4__module);
        tmp_import_name_from_21 = tmp_import_from_4__module;
        if (PyModule_Check(tmp_import_name_from_21)) {
            tmp_assign_source_29 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_21,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[47],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_29 = IMPORT_NAME(tmp_import_name_from_21, mod_consts[47]);
        }

        if (tmp_assign_source_29 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_4;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[47], tmp_assign_source_29);
    }
    {
        PyObject *tmp_assign_source_30;
        PyObject *tmp_import_name_from_22;
        CHECK_OBJECT(tmp_import_from_4__module);
        tmp_import_name_from_22 = tmp_import_from_4__module;
        if (PyModule_Check(tmp_import_name_from_22)) {
            tmp_assign_source_30 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_22,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[48],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_30 = IMPORT_NAME(tmp_import_name_from_22, mod_consts[48]);
        }

        if (tmp_assign_source_30 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 37;

            goto try_except_handler_4;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[48], tmp_assign_source_30);
    }
    goto try_end_4;
    // Exception handler code:
    try_except_handler_4:;
    exception_keeper_type_4 = exception_type;
    exception_keeper_value_4 = exception_value;
    exception_keeper_tb_4 = exception_tb;
    exception_keeper_lineno_4 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_4__module);
    Py_DECREF(tmp_import_from_4__module);
    tmp_import_from_4__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_4;
    exception_value = exception_keeper_value_4;
    exception_tb = exception_keeper_tb_4;
    exception_lineno = exception_keeper_lineno_4;

    goto frame_exception_exit_1;
    // End of try:
    try_end_4:;
    CHECK_OBJECT(tmp_import_from_4__module);
    Py_DECREF(tmp_import_from_4__module);
    tmp_import_from_4__module = NULL;
    {
        PyObject *tmp_assign_source_31;
        PyObject *tmp_name_value_5;
        PyObject *tmp_globals_arg_value_5;
        PyObject *tmp_locals_arg_value_5;
        PyObject *tmp_fromlist_value_5;
        PyObject *tmp_level_value_5;
        tmp_name_value_5 = mod_consts[49];
        tmp_globals_arg_value_5 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_5 = Py_None;
        tmp_fromlist_value_5 = mod_consts[50];
        tmp_level_value_5 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 38;
        tmp_assign_source_31 = IMPORT_MODULE5(tmp_name_value_5, tmp_globals_arg_value_5, tmp_locals_arg_value_5, tmp_fromlist_value_5, tmp_level_value_5);
        if (tmp_assign_source_31 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 38;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_5__module == NULL);
        tmp_import_from_5__module = tmp_assign_source_31;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_32;
        PyObject *tmp_import_name_from_23;
        CHECK_OBJECT(tmp_import_from_5__module);
        tmp_import_name_from_23 = tmp_import_from_5__module;
        if (PyModule_Check(tmp_import_name_from_23)) {
            tmp_assign_source_32 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_23,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[51],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_32 = IMPORT_NAME(tmp_import_name_from_23, mod_consts[51]);
        }

        if (tmp_assign_source_32 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 38;

            goto try_except_handler_5;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[51], tmp_assign_source_32);
    }
    {
        PyObject *tmp_assign_source_33;
        PyObject *tmp_import_name_from_24;
        CHECK_OBJECT(tmp_import_from_5__module);
        tmp_import_name_from_24 = tmp_import_from_5__module;
        if (PyModule_Check(tmp_import_name_from_24)) {
            tmp_assign_source_33 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_24,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[52],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_33 = IMPORT_NAME(tmp_import_name_from_24, mod_consts[52]);
        }

        if (tmp_assign_source_33 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 38;

            goto try_except_handler_5;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[52], tmp_assign_source_33);
    }
    goto try_end_5;
    // Exception handler code:
    try_except_handler_5:;
    exception_keeper_type_5 = exception_type;
    exception_keeper_value_5 = exception_value;
    exception_keeper_tb_5 = exception_tb;
    exception_keeper_lineno_5 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_5__module);
    Py_DECREF(tmp_import_from_5__module);
    tmp_import_from_5__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_5;
    exception_value = exception_keeper_value_5;
    exception_tb = exception_keeper_tb_5;
    exception_lineno = exception_keeper_lineno_5;

    goto frame_exception_exit_1;
    // End of try:
    try_end_5:;
    CHECK_OBJECT(tmp_import_from_5__module);
    Py_DECREF(tmp_import_from_5__module);
    tmp_import_from_5__module = NULL;
    {
        PyObject *tmp_assign_source_34;
        PyObject *tmp_import_name_from_25;
        PyObject *tmp_name_value_6;
        PyObject *tmp_globals_arg_value_6;
        PyObject *tmp_locals_arg_value_6;
        PyObject *tmp_fromlist_value_6;
        PyObject *tmp_level_value_6;
        tmp_name_value_6 = mod_consts[53];
        tmp_globals_arg_value_6 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_6 = Py_None;
        tmp_fromlist_value_6 = mod_consts[54];
        tmp_level_value_6 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 39;
        tmp_import_name_from_25 = IMPORT_MODULE5(tmp_name_value_6, tmp_globals_arg_value_6, tmp_locals_arg_value_6, tmp_fromlist_value_6, tmp_level_value_6);
        if (tmp_import_name_from_25 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 39;

            goto frame_exception_exit_1;
        }
        if (PyModule_Check(tmp_import_name_from_25)) {
            tmp_assign_source_34 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_25,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[55],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_34 = IMPORT_NAME(tmp_import_name_from_25, mod_consts[55]);
        }

        Py_DECREF(tmp_import_name_from_25);
        if (tmp_assign_source_34 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 39;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[55], tmp_assign_source_34);
    }
    {
        PyObject *tmp_assign_source_35;
        PyObject *tmp_name_value_7;
        PyObject *tmp_globals_arg_value_7;
        PyObject *tmp_locals_arg_value_7;
        PyObject *tmp_fromlist_value_7;
        PyObject *tmp_level_value_7;
        tmp_name_value_7 = mod_consts[31];
        tmp_globals_arg_value_7 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_7 = Py_None;
        tmp_fromlist_value_7 = mod_consts[56];
        tmp_level_value_7 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 40;
        tmp_assign_source_35 = IMPORT_MODULE5(tmp_name_value_7, tmp_globals_arg_value_7, tmp_locals_arg_value_7, tmp_fromlist_value_7, tmp_level_value_7);
        if (tmp_assign_source_35 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_6__module == NULL);
        tmp_import_from_6__module = tmp_assign_source_35;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_36;
        PyObject *tmp_import_name_from_26;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_26 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_26)) {
            tmp_assign_source_36 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_26,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[57],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_36 = IMPORT_NAME(tmp_import_name_from_26, mod_consts[57]);
        }

        if (tmp_assign_source_36 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[57], tmp_assign_source_36);
    }
    {
        PyObject *tmp_assign_source_37;
        PyObject *tmp_import_name_from_27;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_27 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_27)) {
            tmp_assign_source_37 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_27,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[58],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_37 = IMPORT_NAME(tmp_import_name_from_27, mod_consts[58]);
        }

        if (tmp_assign_source_37 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[58], tmp_assign_source_37);
    }
    {
        PyObject *tmp_assign_source_38;
        PyObject *tmp_import_name_from_28;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_28 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_28)) {
            tmp_assign_source_38 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_28,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[59],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_38 = IMPORT_NAME(tmp_import_name_from_28, mod_consts[59]);
        }

        if (tmp_assign_source_38 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[59], tmp_assign_source_38);
    }
    {
        PyObject *tmp_assign_source_39;
        PyObject *tmp_import_name_from_29;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_29 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_29)) {
            tmp_assign_source_39 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_29,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[60],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_39 = IMPORT_NAME(tmp_import_name_from_29, mod_consts[60]);
        }

        if (tmp_assign_source_39 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[60], tmp_assign_source_39);
    }
    {
        PyObject *tmp_assign_source_40;
        PyObject *tmp_import_name_from_30;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_30 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_30)) {
            tmp_assign_source_40 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_30,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[61],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_40 = IMPORT_NAME(tmp_import_name_from_30, mod_consts[61]);
        }

        if (tmp_assign_source_40 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[61], tmp_assign_source_40);
    }
    {
        PyObject *tmp_assign_source_41;
        PyObject *tmp_import_name_from_31;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_31 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_31)) {
            tmp_assign_source_41 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_31,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[62],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_41 = IMPORT_NAME(tmp_import_name_from_31, mod_consts[62]);
        }

        if (tmp_assign_source_41 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[62], tmp_assign_source_41);
    }
    {
        PyObject *tmp_assign_source_42;
        PyObject *tmp_import_name_from_32;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_32 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_32)) {
            tmp_assign_source_42 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_32,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[63],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_42 = IMPORT_NAME(tmp_import_name_from_32, mod_consts[63]);
        }

        if (tmp_assign_source_42 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[63], tmp_assign_source_42);
    }
    {
        PyObject *tmp_assign_source_43;
        PyObject *tmp_import_name_from_33;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_33 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_33)) {
            tmp_assign_source_43 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_33,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[64],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_43 = IMPORT_NAME(tmp_import_name_from_33, mod_consts[64]);
        }

        if (tmp_assign_source_43 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[64], tmp_assign_source_43);
    }
    {
        PyObject *tmp_assign_source_44;
        PyObject *tmp_import_name_from_34;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_34 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_34)) {
            tmp_assign_source_44 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_34,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[65],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_44 = IMPORT_NAME(tmp_import_name_from_34, mod_consts[65]);
        }

        if (tmp_assign_source_44 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[65], tmp_assign_source_44);
    }
    {
        PyObject *tmp_assign_source_45;
        PyObject *tmp_import_name_from_35;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_35 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_35)) {
            tmp_assign_source_45 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_35,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[66],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_45 = IMPORT_NAME(tmp_import_name_from_35, mod_consts[66]);
        }

        if (tmp_assign_source_45 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[66], tmp_assign_source_45);
    }
    {
        PyObject *tmp_assign_source_46;
        PyObject *tmp_import_name_from_36;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_36 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_36)) {
            tmp_assign_source_46 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_36,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[67],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_46 = IMPORT_NAME(tmp_import_name_from_36, mod_consts[67]);
        }

        if (tmp_assign_source_46 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[67], tmp_assign_source_46);
    }
    {
        PyObject *tmp_assign_source_47;
        PyObject *tmp_import_name_from_37;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_37 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_37)) {
            tmp_assign_source_47 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_37,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[68],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_47 = IMPORT_NAME(tmp_import_name_from_37, mod_consts[68]);
        }

        if (tmp_assign_source_47 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[68], tmp_assign_source_47);
    }
    {
        PyObject *tmp_assign_source_48;
        PyObject *tmp_import_name_from_38;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_38 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_38)) {
            tmp_assign_source_48 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_38,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[69],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_48 = IMPORT_NAME(tmp_import_name_from_38, mod_consts[69]);
        }

        if (tmp_assign_source_48 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[69], tmp_assign_source_48);
    }
    {
        PyObject *tmp_assign_source_49;
        PyObject *tmp_import_name_from_39;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_39 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_39)) {
            tmp_assign_source_49 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_39,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[70],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_49 = IMPORT_NAME(tmp_import_name_from_39, mod_consts[70]);
        }

        if (tmp_assign_source_49 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[70], tmp_assign_source_49);
    }
    {
        PyObject *tmp_assign_source_50;
        PyObject *tmp_import_name_from_40;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_40 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_40)) {
            tmp_assign_source_50 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_40,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[71],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_50 = IMPORT_NAME(tmp_import_name_from_40, mod_consts[71]);
        }

        if (tmp_assign_source_50 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[71], tmp_assign_source_50);
    }
    {
        PyObject *tmp_assign_source_51;
        PyObject *tmp_import_name_from_41;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_41 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_41)) {
            tmp_assign_source_51 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_41,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[72],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_51 = IMPORT_NAME(tmp_import_name_from_41, mod_consts[72]);
        }

        if (tmp_assign_source_51 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[72], tmp_assign_source_51);
    }
    {
        PyObject *tmp_assign_source_52;
        PyObject *tmp_import_name_from_42;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_42 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_42)) {
            tmp_assign_source_52 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_42,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[73],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_52 = IMPORT_NAME(tmp_import_name_from_42, mod_consts[73]);
        }

        if (tmp_assign_source_52 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[73], tmp_assign_source_52);
    }
    {
        PyObject *tmp_assign_source_53;
        PyObject *tmp_import_name_from_43;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_43 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_43)) {
            tmp_assign_source_53 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_43,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[74],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_53 = IMPORT_NAME(tmp_import_name_from_43, mod_consts[74]);
        }

        if (tmp_assign_source_53 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[74], tmp_assign_source_53);
    }
    {
        PyObject *tmp_assign_source_54;
        PyObject *tmp_import_name_from_44;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_44 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_44)) {
            tmp_assign_source_54 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_44,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[75],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_54 = IMPORT_NAME(tmp_import_name_from_44, mod_consts[75]);
        }

        if (tmp_assign_source_54 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[75], tmp_assign_source_54);
    }
    {
        PyObject *tmp_assign_source_55;
        PyObject *tmp_import_name_from_45;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_45 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_45)) {
            tmp_assign_source_55 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_45,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[76],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_55 = IMPORT_NAME(tmp_import_name_from_45, mod_consts[76]);
        }

        if (tmp_assign_source_55 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[76], tmp_assign_source_55);
    }
    {
        PyObject *tmp_assign_source_56;
        PyObject *tmp_import_name_from_46;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_46 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_46)) {
            tmp_assign_source_56 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_46,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[77],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_56 = IMPORT_NAME(tmp_import_name_from_46, mod_consts[77]);
        }

        if (tmp_assign_source_56 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[77], tmp_assign_source_56);
    }
    {
        PyObject *tmp_assign_source_57;
        PyObject *tmp_import_name_from_47;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_47 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_47)) {
            tmp_assign_source_57 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_47,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[78],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_57 = IMPORT_NAME(tmp_import_name_from_47, mod_consts[78]);
        }

        if (tmp_assign_source_57 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[78], tmp_assign_source_57);
    }
    {
        PyObject *tmp_assign_source_58;
        PyObject *tmp_import_name_from_48;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_48 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_48)) {
            tmp_assign_source_58 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_48,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[79],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_58 = IMPORT_NAME(tmp_import_name_from_48, mod_consts[79]);
        }

        if (tmp_assign_source_58 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[79], tmp_assign_source_58);
    }
    {
        PyObject *tmp_assign_source_59;
        PyObject *tmp_import_name_from_49;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_49 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_49)) {
            tmp_assign_source_59 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_49,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[80],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_59 = IMPORT_NAME(tmp_import_name_from_49, mod_consts[80]);
        }

        if (tmp_assign_source_59 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[80], tmp_assign_source_59);
    }
    {
        PyObject *tmp_assign_source_60;
        PyObject *tmp_import_name_from_50;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_50 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_50)) {
            tmp_assign_source_60 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_50,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[81],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_60 = IMPORT_NAME(tmp_import_name_from_50, mod_consts[81]);
        }

        if (tmp_assign_source_60 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[81], tmp_assign_source_60);
    }
    {
        PyObject *tmp_assign_source_61;
        PyObject *tmp_import_name_from_51;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_51 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_51)) {
            tmp_assign_source_61 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_51,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[82],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_61 = IMPORT_NAME(tmp_import_name_from_51, mod_consts[82]);
        }

        if (tmp_assign_source_61 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[82], tmp_assign_source_61);
    }
    {
        PyObject *tmp_assign_source_62;
        PyObject *tmp_import_name_from_52;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_52 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_52)) {
            tmp_assign_source_62 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_52,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[83],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_62 = IMPORT_NAME(tmp_import_name_from_52, mod_consts[83]);
        }

        if (tmp_assign_source_62 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[83], tmp_assign_source_62);
    }
    {
        PyObject *tmp_assign_source_63;
        PyObject *tmp_import_name_from_53;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_53 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_53)) {
            tmp_assign_source_63 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_53,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[84],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_63 = IMPORT_NAME(tmp_import_name_from_53, mod_consts[84]);
        }

        if (tmp_assign_source_63 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[84], tmp_assign_source_63);
    }
    {
        PyObject *tmp_assign_source_64;
        PyObject *tmp_import_name_from_54;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_54 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_54)) {
            tmp_assign_source_64 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_54,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[85],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_64 = IMPORT_NAME(tmp_import_name_from_54, mod_consts[85]);
        }

        if (tmp_assign_source_64 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[85], tmp_assign_source_64);
    }
    {
        PyObject *tmp_assign_source_65;
        PyObject *tmp_import_name_from_55;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_55 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_55)) {
            tmp_assign_source_65 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_55,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[86],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_65 = IMPORT_NAME(tmp_import_name_from_55, mod_consts[86]);
        }

        if (tmp_assign_source_65 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[86], tmp_assign_source_65);
    }
    {
        PyObject *tmp_assign_source_66;
        PyObject *tmp_import_name_from_56;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_56 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_56)) {
            tmp_assign_source_66 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_56,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[87],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_66 = IMPORT_NAME(tmp_import_name_from_56, mod_consts[87]);
        }

        if (tmp_assign_source_66 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[87], tmp_assign_source_66);
    }
    {
        PyObject *tmp_assign_source_67;
        PyObject *tmp_import_name_from_57;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_57 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_57)) {
            tmp_assign_source_67 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_57,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[88],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_67 = IMPORT_NAME(tmp_import_name_from_57, mod_consts[88]);
        }

        if (tmp_assign_source_67 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[88], tmp_assign_source_67);
    }
    {
        PyObject *tmp_assign_source_68;
        PyObject *tmp_import_name_from_58;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_58 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_58)) {
            tmp_assign_source_68 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_58,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[89],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_68 = IMPORT_NAME(tmp_import_name_from_58, mod_consts[89]);
        }

        if (tmp_assign_source_68 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[89], tmp_assign_source_68);
    }
    {
        PyObject *tmp_assign_source_69;
        PyObject *tmp_import_name_from_59;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_59 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_59)) {
            tmp_assign_source_69 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_59,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[90],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_69 = IMPORT_NAME(tmp_import_name_from_59, mod_consts[90]);
        }

        if (tmp_assign_source_69 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[90], tmp_assign_source_69);
    }
    {
        PyObject *tmp_assign_source_70;
        PyObject *tmp_import_name_from_60;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_60 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_60)) {
            tmp_assign_source_70 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_60,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[91],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_70 = IMPORT_NAME(tmp_import_name_from_60, mod_consts[91]);
        }

        if (tmp_assign_source_70 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[91], tmp_assign_source_70);
    }
    {
        PyObject *tmp_assign_source_71;
        PyObject *tmp_import_name_from_61;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_61 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_61)) {
            tmp_assign_source_71 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_61,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[92],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_71 = IMPORT_NAME(tmp_import_name_from_61, mod_consts[92]);
        }

        if (tmp_assign_source_71 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[92], tmp_assign_source_71);
    }
    {
        PyObject *tmp_assign_source_72;
        PyObject *tmp_import_name_from_62;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_62 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_62)) {
            tmp_assign_source_72 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_62,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[93],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_72 = IMPORT_NAME(tmp_import_name_from_62, mod_consts[93]);
        }

        if (tmp_assign_source_72 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[93], tmp_assign_source_72);
    }
    {
        PyObject *tmp_assign_source_73;
        PyObject *tmp_import_name_from_63;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_63 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_63)) {
            tmp_assign_source_73 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_63,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[94],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_73 = IMPORT_NAME(tmp_import_name_from_63, mod_consts[94]);
        }

        if (tmp_assign_source_73 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[94], tmp_assign_source_73);
    }
    {
        PyObject *tmp_assign_source_74;
        PyObject *tmp_import_name_from_64;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_64 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_64)) {
            tmp_assign_source_74 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_64,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[95],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_74 = IMPORT_NAME(tmp_import_name_from_64, mod_consts[95]);
        }

        if (tmp_assign_source_74 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[95], tmp_assign_source_74);
    }
    {
        PyObject *tmp_assign_source_75;
        PyObject *tmp_import_name_from_65;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_65 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_65)) {
            tmp_assign_source_75 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_65,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[96],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_75 = IMPORT_NAME(tmp_import_name_from_65, mod_consts[96]);
        }

        if (tmp_assign_source_75 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[96], tmp_assign_source_75);
    }
    {
        PyObject *tmp_assign_source_76;
        PyObject *tmp_import_name_from_66;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_66 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_66)) {
            tmp_assign_source_76 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_66,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[97],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_76 = IMPORT_NAME(tmp_import_name_from_66, mod_consts[97]);
        }

        if (tmp_assign_source_76 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[97], tmp_assign_source_76);
    }
    {
        PyObject *tmp_assign_source_77;
        PyObject *tmp_import_name_from_67;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_67 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_67)) {
            tmp_assign_source_77 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_67,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[98],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_77 = IMPORT_NAME(tmp_import_name_from_67, mod_consts[98]);
        }

        if (tmp_assign_source_77 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[98], tmp_assign_source_77);
    }
    {
        PyObject *tmp_assign_source_78;
        PyObject *tmp_import_name_from_68;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_68 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_68)) {
            tmp_assign_source_78 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_68,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[99],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_78 = IMPORT_NAME(tmp_import_name_from_68, mod_consts[99]);
        }

        if (tmp_assign_source_78 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[99], tmp_assign_source_78);
    }
    {
        PyObject *tmp_assign_source_79;
        PyObject *tmp_import_name_from_69;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_69 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_69)) {
            tmp_assign_source_79 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_69,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[100],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_79 = IMPORT_NAME(tmp_import_name_from_69, mod_consts[100]);
        }

        if (tmp_assign_source_79 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[100], tmp_assign_source_79);
    }
    {
        PyObject *tmp_assign_source_80;
        PyObject *tmp_import_name_from_70;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_70 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_70)) {
            tmp_assign_source_80 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_70,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[101],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_80 = IMPORT_NAME(tmp_import_name_from_70, mod_consts[101]);
        }

        if (tmp_assign_source_80 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[101], tmp_assign_source_80);
    }
    {
        PyObject *tmp_assign_source_81;
        PyObject *tmp_import_name_from_71;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_71 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_71)) {
            tmp_assign_source_81 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_71,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[102],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_81 = IMPORT_NAME(tmp_import_name_from_71, mod_consts[102]);
        }

        if (tmp_assign_source_81 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[102], tmp_assign_source_81);
    }
    {
        PyObject *tmp_assign_source_82;
        PyObject *tmp_import_name_from_72;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_72 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_72)) {
            tmp_assign_source_82 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_72,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[103],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_82 = IMPORT_NAME(tmp_import_name_from_72, mod_consts[103]);
        }

        if (tmp_assign_source_82 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[103], tmp_assign_source_82);
    }
    {
        PyObject *tmp_assign_source_83;
        PyObject *tmp_import_name_from_73;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_73 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_73)) {
            tmp_assign_source_83 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_73,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[104],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_83 = IMPORT_NAME(tmp_import_name_from_73, mod_consts[104]);
        }

        if (tmp_assign_source_83 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[104], tmp_assign_source_83);
    }
    {
        PyObject *tmp_assign_source_84;
        PyObject *tmp_import_name_from_74;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_74 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_74)) {
            tmp_assign_source_84 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_74,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[105],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_84 = IMPORT_NAME(tmp_import_name_from_74, mod_consts[105]);
        }

        if (tmp_assign_source_84 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[105], tmp_assign_source_84);
    }
    {
        PyObject *tmp_assign_source_85;
        PyObject *tmp_import_name_from_75;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_75 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_75)) {
            tmp_assign_source_85 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_75,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[106],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_85 = IMPORT_NAME(tmp_import_name_from_75, mod_consts[106]);
        }

        if (tmp_assign_source_85 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[106], tmp_assign_source_85);
    }
    {
        PyObject *tmp_assign_source_86;
        PyObject *tmp_import_name_from_76;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_76 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_76)) {
            tmp_assign_source_86 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_76,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[107],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_86 = IMPORT_NAME(tmp_import_name_from_76, mod_consts[107]);
        }

        if (tmp_assign_source_86 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[107], tmp_assign_source_86);
    }
    {
        PyObject *tmp_assign_source_87;
        PyObject *tmp_import_name_from_77;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_77 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_77)) {
            tmp_assign_source_87 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_77,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[108],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_87 = IMPORT_NAME(tmp_import_name_from_77, mod_consts[108]);
        }

        if (tmp_assign_source_87 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[108], tmp_assign_source_87);
    }
    {
        PyObject *tmp_assign_source_88;
        PyObject *tmp_import_name_from_78;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_78 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_78)) {
            tmp_assign_source_88 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_78,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[109],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_88 = IMPORT_NAME(tmp_import_name_from_78, mod_consts[109]);
        }

        if (tmp_assign_source_88 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[109], tmp_assign_source_88);
    }
    {
        PyObject *tmp_assign_source_89;
        PyObject *tmp_import_name_from_79;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_79 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_79)) {
            tmp_assign_source_89 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_79,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[110],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_89 = IMPORT_NAME(tmp_import_name_from_79, mod_consts[110]);
        }

        if (tmp_assign_source_89 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[110], tmp_assign_source_89);
    }
    {
        PyObject *tmp_assign_source_90;
        PyObject *tmp_import_name_from_80;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_80 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_80)) {
            tmp_assign_source_90 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_80,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[111],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_90 = IMPORT_NAME(tmp_import_name_from_80, mod_consts[111]);
        }

        if (tmp_assign_source_90 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[111], tmp_assign_source_90);
    }
    {
        PyObject *tmp_assign_source_91;
        PyObject *tmp_import_name_from_81;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_81 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_81)) {
            tmp_assign_source_91 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_81,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[112],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_91 = IMPORT_NAME(tmp_import_name_from_81, mod_consts[112]);
        }

        if (tmp_assign_source_91 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[112], tmp_assign_source_91);
    }
    {
        PyObject *tmp_assign_source_92;
        PyObject *tmp_import_name_from_82;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_82 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_82)) {
            tmp_assign_source_92 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_82,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[113],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_92 = IMPORT_NAME(tmp_import_name_from_82, mod_consts[113]);
        }

        if (tmp_assign_source_92 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[113], tmp_assign_source_92);
    }
    {
        PyObject *tmp_assign_source_93;
        PyObject *tmp_import_name_from_83;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_83 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_83)) {
            tmp_assign_source_93 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_83,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[114],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_93 = IMPORT_NAME(tmp_import_name_from_83, mod_consts[114]);
        }

        if (tmp_assign_source_93 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[114], tmp_assign_source_93);
    }
    {
        PyObject *tmp_assign_source_94;
        PyObject *tmp_import_name_from_84;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_84 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_84)) {
            tmp_assign_source_94 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_84,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[115],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_94 = IMPORT_NAME(tmp_import_name_from_84, mod_consts[115]);
        }

        if (tmp_assign_source_94 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[115], tmp_assign_source_94);
    }
    {
        PyObject *tmp_assign_source_95;
        PyObject *tmp_import_name_from_85;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_85 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_85)) {
            tmp_assign_source_95 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_85,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[116],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_95 = IMPORT_NAME(tmp_import_name_from_85, mod_consts[116]);
        }

        if (tmp_assign_source_95 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[116], tmp_assign_source_95);
    }
    {
        PyObject *tmp_assign_source_96;
        PyObject *tmp_import_name_from_86;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_86 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_86)) {
            tmp_assign_source_96 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_86,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[117],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_96 = IMPORT_NAME(tmp_import_name_from_86, mod_consts[117]);
        }

        if (tmp_assign_source_96 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[117], tmp_assign_source_96);
    }
    {
        PyObject *tmp_assign_source_97;
        PyObject *tmp_import_name_from_87;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_87 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_87)) {
            tmp_assign_source_97 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_87,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[118],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_97 = IMPORT_NAME(tmp_import_name_from_87, mod_consts[118]);
        }

        if (tmp_assign_source_97 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[118], tmp_assign_source_97);
    }
    {
        PyObject *tmp_assign_source_98;
        PyObject *tmp_import_name_from_88;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_88 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_88)) {
            tmp_assign_source_98 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_88,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[119],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_98 = IMPORT_NAME(tmp_import_name_from_88, mod_consts[119]);
        }

        if (tmp_assign_source_98 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[119], tmp_assign_source_98);
    }
    {
        PyObject *tmp_assign_source_99;
        PyObject *tmp_import_name_from_89;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_89 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_89)) {
            tmp_assign_source_99 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_89,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[120],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_99 = IMPORT_NAME(tmp_import_name_from_89, mod_consts[120]);
        }

        if (tmp_assign_source_99 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[120], tmp_assign_source_99);
    }
    {
        PyObject *tmp_assign_source_100;
        PyObject *tmp_import_name_from_90;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_90 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_90)) {
            tmp_assign_source_100 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_90,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[121],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_100 = IMPORT_NAME(tmp_import_name_from_90, mod_consts[121]);
        }

        if (tmp_assign_source_100 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[121], tmp_assign_source_100);
    }
    {
        PyObject *tmp_assign_source_101;
        PyObject *tmp_import_name_from_91;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_91 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_91)) {
            tmp_assign_source_101 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_91,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[122],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_101 = IMPORT_NAME(tmp_import_name_from_91, mod_consts[122]);
        }

        if (tmp_assign_source_101 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[122], tmp_assign_source_101);
    }
    {
        PyObject *tmp_assign_source_102;
        PyObject *tmp_import_name_from_92;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_92 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_92)) {
            tmp_assign_source_102 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_92,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[123],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_102 = IMPORT_NAME(tmp_import_name_from_92, mod_consts[123]);
        }

        if (tmp_assign_source_102 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[123], tmp_assign_source_102);
    }
    {
        PyObject *tmp_assign_source_103;
        PyObject *tmp_import_name_from_93;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_93 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_93)) {
            tmp_assign_source_103 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_93,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[124],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_103 = IMPORT_NAME(tmp_import_name_from_93, mod_consts[124]);
        }

        if (tmp_assign_source_103 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[124], tmp_assign_source_103);
    }
    {
        PyObject *tmp_assign_source_104;
        PyObject *tmp_import_name_from_94;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_94 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_94)) {
            tmp_assign_source_104 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_94,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[125],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_104 = IMPORT_NAME(tmp_import_name_from_94, mod_consts[125]);
        }

        if (tmp_assign_source_104 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[125], tmp_assign_source_104);
    }
    {
        PyObject *tmp_assign_source_105;
        PyObject *tmp_import_name_from_95;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_95 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_95)) {
            tmp_assign_source_105 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_95,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[126],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_105 = IMPORT_NAME(tmp_import_name_from_95, mod_consts[126]);
        }

        if (tmp_assign_source_105 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[126], tmp_assign_source_105);
    }
    {
        PyObject *tmp_assign_source_106;
        PyObject *tmp_import_name_from_96;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_96 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_96)) {
            tmp_assign_source_106 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_96,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[127],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_106 = IMPORT_NAME(tmp_import_name_from_96, mod_consts[127]);
        }

        if (tmp_assign_source_106 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[127], tmp_assign_source_106);
    }
    {
        PyObject *tmp_assign_source_107;
        PyObject *tmp_import_name_from_97;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_97 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_97)) {
            tmp_assign_source_107 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_97,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[128],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_107 = IMPORT_NAME(tmp_import_name_from_97, mod_consts[128]);
        }

        if (tmp_assign_source_107 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[128], tmp_assign_source_107);
    }
    {
        PyObject *tmp_assign_source_108;
        PyObject *tmp_import_name_from_98;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_98 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_98)) {
            tmp_assign_source_108 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_98,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[129],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_108 = IMPORT_NAME(tmp_import_name_from_98, mod_consts[129]);
        }

        if (tmp_assign_source_108 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[129], tmp_assign_source_108);
    }
    {
        PyObject *tmp_assign_source_109;
        PyObject *tmp_import_name_from_99;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_99 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_99)) {
            tmp_assign_source_109 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_99,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[130],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_109 = IMPORT_NAME(tmp_import_name_from_99, mod_consts[130]);
        }

        if (tmp_assign_source_109 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[130], tmp_assign_source_109);
    }
    {
        PyObject *tmp_assign_source_110;
        PyObject *tmp_import_name_from_100;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_100 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_100)) {
            tmp_assign_source_110 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_100,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[131],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_110 = IMPORT_NAME(tmp_import_name_from_100, mod_consts[131]);
        }

        if (tmp_assign_source_110 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[131], tmp_assign_source_110);
    }
    {
        PyObject *tmp_assign_source_111;
        PyObject *tmp_import_name_from_101;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_101 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_101)) {
            tmp_assign_source_111 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_101,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[132],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_111 = IMPORT_NAME(tmp_import_name_from_101, mod_consts[132]);
        }

        if (tmp_assign_source_111 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[132], tmp_assign_source_111);
    }
    {
        PyObject *tmp_assign_source_112;
        PyObject *tmp_import_name_from_102;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_102 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_102)) {
            tmp_assign_source_112 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_102,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[133],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_112 = IMPORT_NAME(tmp_import_name_from_102, mod_consts[133]);
        }

        if (tmp_assign_source_112 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[133], tmp_assign_source_112);
    }
    {
        PyObject *tmp_assign_source_113;
        PyObject *tmp_import_name_from_103;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_103 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_103)) {
            tmp_assign_source_113 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_103,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[134],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_113 = IMPORT_NAME(tmp_import_name_from_103, mod_consts[134]);
        }

        if (tmp_assign_source_113 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[134], tmp_assign_source_113);
    }
    {
        PyObject *tmp_assign_source_114;
        PyObject *tmp_import_name_from_104;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_104 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_104)) {
            tmp_assign_source_114 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_104,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[135],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_114 = IMPORT_NAME(tmp_import_name_from_104, mod_consts[135]);
        }

        if (tmp_assign_source_114 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[135], tmp_assign_source_114);
    }
    {
        PyObject *tmp_assign_source_115;
        PyObject *tmp_import_name_from_105;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_105 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_105)) {
            tmp_assign_source_115 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_105,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[136],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_115 = IMPORT_NAME(tmp_import_name_from_105, mod_consts[136]);
        }

        if (tmp_assign_source_115 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[136], tmp_assign_source_115);
    }
    {
        PyObject *tmp_assign_source_116;
        PyObject *tmp_import_name_from_106;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_106 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_106)) {
            tmp_assign_source_116 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_106,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[137],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_116 = IMPORT_NAME(tmp_import_name_from_106, mod_consts[137]);
        }

        if (tmp_assign_source_116 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[137], tmp_assign_source_116);
    }
    {
        PyObject *tmp_assign_source_117;
        PyObject *tmp_import_name_from_107;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_107 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_107)) {
            tmp_assign_source_117 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_107,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[138],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_117 = IMPORT_NAME(tmp_import_name_from_107, mod_consts[138]);
        }

        if (tmp_assign_source_117 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[138], tmp_assign_source_117);
    }
    {
        PyObject *tmp_assign_source_118;
        PyObject *tmp_import_name_from_108;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_108 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_108)) {
            tmp_assign_source_118 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_108,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[139],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_118 = IMPORT_NAME(tmp_import_name_from_108, mod_consts[139]);
        }

        if (tmp_assign_source_118 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[139], tmp_assign_source_118);
    }
    {
        PyObject *tmp_assign_source_119;
        PyObject *tmp_import_name_from_109;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_109 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_109)) {
            tmp_assign_source_119 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_109,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[140],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_119 = IMPORT_NAME(tmp_import_name_from_109, mod_consts[140]);
        }

        if (tmp_assign_source_119 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[140], tmp_assign_source_119);
    }
    {
        PyObject *tmp_assign_source_120;
        PyObject *tmp_import_name_from_110;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_110 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_110)) {
            tmp_assign_source_120 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_110,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[141],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_120 = IMPORT_NAME(tmp_import_name_from_110, mod_consts[141]);
        }

        if (tmp_assign_source_120 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[141], tmp_assign_source_120);
    }
    {
        PyObject *tmp_assign_source_121;
        PyObject *tmp_import_name_from_111;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_111 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_111)) {
            tmp_assign_source_121 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_111,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[142],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_121 = IMPORT_NAME(tmp_import_name_from_111, mod_consts[142]);
        }

        if (tmp_assign_source_121 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[142], tmp_assign_source_121);
    }
    {
        PyObject *tmp_assign_source_122;
        PyObject *tmp_import_name_from_112;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_112 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_112)) {
            tmp_assign_source_122 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_112,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[143],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_122 = IMPORT_NAME(tmp_import_name_from_112, mod_consts[143]);
        }

        if (tmp_assign_source_122 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[143], tmp_assign_source_122);
    }
    {
        PyObject *tmp_assign_source_123;
        PyObject *tmp_import_name_from_113;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_113 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_113)) {
            tmp_assign_source_123 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_113,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[144],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_123 = IMPORT_NAME(tmp_import_name_from_113, mod_consts[144]);
        }

        if (tmp_assign_source_123 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[144], tmp_assign_source_123);
    }
    {
        PyObject *tmp_assign_source_124;
        PyObject *tmp_import_name_from_114;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_114 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_114)) {
            tmp_assign_source_124 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_114,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[145],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_124 = IMPORT_NAME(tmp_import_name_from_114, mod_consts[145]);
        }

        if (tmp_assign_source_124 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[145], tmp_assign_source_124);
    }
    {
        PyObject *tmp_assign_source_125;
        PyObject *tmp_import_name_from_115;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_115 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_115)) {
            tmp_assign_source_125 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_115,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[146],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_125 = IMPORT_NAME(tmp_import_name_from_115, mod_consts[146]);
        }

        if (tmp_assign_source_125 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[146], tmp_assign_source_125);
    }
    {
        PyObject *tmp_assign_source_126;
        PyObject *tmp_import_name_from_116;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_116 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_116)) {
            tmp_assign_source_126 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_116,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[147],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_126 = IMPORT_NAME(tmp_import_name_from_116, mod_consts[147]);
        }

        if (tmp_assign_source_126 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[147], tmp_assign_source_126);
    }
    {
        PyObject *tmp_assign_source_127;
        PyObject *tmp_import_name_from_117;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_117 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_117)) {
            tmp_assign_source_127 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_117,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[148],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_127 = IMPORT_NAME(tmp_import_name_from_117, mod_consts[148]);
        }

        if (tmp_assign_source_127 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[148], tmp_assign_source_127);
    }
    {
        PyObject *tmp_assign_source_128;
        PyObject *tmp_import_name_from_118;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_118 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_118)) {
            tmp_assign_source_128 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_118,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[149],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_128 = IMPORT_NAME(tmp_import_name_from_118, mod_consts[149]);
        }

        if (tmp_assign_source_128 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[149], tmp_assign_source_128);
    }
    {
        PyObject *tmp_assign_source_129;
        PyObject *tmp_import_name_from_119;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_119 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_119)) {
            tmp_assign_source_129 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_119,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[150],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_129 = IMPORT_NAME(tmp_import_name_from_119, mod_consts[150]);
        }

        if (tmp_assign_source_129 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[150], tmp_assign_source_129);
    }
    {
        PyObject *tmp_assign_source_130;
        PyObject *tmp_import_name_from_120;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_120 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_120)) {
            tmp_assign_source_130 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_120,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[151],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_130 = IMPORT_NAME(tmp_import_name_from_120, mod_consts[151]);
        }

        if (tmp_assign_source_130 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[151], tmp_assign_source_130);
    }
    {
        PyObject *tmp_assign_source_131;
        PyObject *tmp_import_name_from_121;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_121 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_121)) {
            tmp_assign_source_131 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_121,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[152],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_131 = IMPORT_NAME(tmp_import_name_from_121, mod_consts[152]);
        }

        if (tmp_assign_source_131 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[152], tmp_assign_source_131);
    }
    {
        PyObject *tmp_assign_source_132;
        PyObject *tmp_import_name_from_122;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_122 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_122)) {
            tmp_assign_source_132 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_122,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[153],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_132 = IMPORT_NAME(tmp_import_name_from_122, mod_consts[153]);
        }

        if (tmp_assign_source_132 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[153], tmp_assign_source_132);
    }
    {
        PyObject *tmp_assign_source_133;
        PyObject *tmp_import_name_from_123;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_123 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_123)) {
            tmp_assign_source_133 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_123,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[154],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_133 = IMPORT_NAME(tmp_import_name_from_123, mod_consts[154]);
        }

        if (tmp_assign_source_133 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[154], tmp_assign_source_133);
    }
    {
        PyObject *tmp_assign_source_134;
        PyObject *tmp_import_name_from_124;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_124 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_124)) {
            tmp_assign_source_134 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_124,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[155],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_134 = IMPORT_NAME(tmp_import_name_from_124, mod_consts[155]);
        }

        if (tmp_assign_source_134 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[155], tmp_assign_source_134);
    }
    {
        PyObject *tmp_assign_source_135;
        PyObject *tmp_import_name_from_125;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_125 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_125)) {
            tmp_assign_source_135 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_125,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[156],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_135 = IMPORT_NAME(tmp_import_name_from_125, mod_consts[156]);
        }

        if (tmp_assign_source_135 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[156], tmp_assign_source_135);
    }
    {
        PyObject *tmp_assign_source_136;
        PyObject *tmp_import_name_from_126;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_126 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_126)) {
            tmp_assign_source_136 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_126,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[157],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_136 = IMPORT_NAME(tmp_import_name_from_126, mod_consts[157]);
        }

        if (tmp_assign_source_136 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[157], tmp_assign_source_136);
    }
    {
        PyObject *tmp_assign_source_137;
        PyObject *tmp_import_name_from_127;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_127 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_127)) {
            tmp_assign_source_137 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_127,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[158],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_137 = IMPORT_NAME(tmp_import_name_from_127, mod_consts[158]);
        }

        if (tmp_assign_source_137 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[158], tmp_assign_source_137);
    }
    {
        PyObject *tmp_assign_source_138;
        PyObject *tmp_import_name_from_128;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_128 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_128)) {
            tmp_assign_source_138 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_128,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[159],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_138 = IMPORT_NAME(tmp_import_name_from_128, mod_consts[159]);
        }

        if (tmp_assign_source_138 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[159], tmp_assign_source_138);
    }
    {
        PyObject *tmp_assign_source_139;
        PyObject *tmp_import_name_from_129;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_129 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_129)) {
            tmp_assign_source_139 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_129,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[160],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_139 = IMPORT_NAME(tmp_import_name_from_129, mod_consts[160]);
        }

        if (tmp_assign_source_139 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[160], tmp_assign_source_139);
    }
    {
        PyObject *tmp_assign_source_140;
        PyObject *tmp_import_name_from_130;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_130 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_130)) {
            tmp_assign_source_140 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_130,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[161],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_140 = IMPORT_NAME(tmp_import_name_from_130, mod_consts[161]);
        }

        if (tmp_assign_source_140 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[161], tmp_assign_source_140);
    }
    {
        PyObject *tmp_assign_source_141;
        PyObject *tmp_import_name_from_131;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_131 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_131)) {
            tmp_assign_source_141 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_131,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[162],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_141 = IMPORT_NAME(tmp_import_name_from_131, mod_consts[162]);
        }

        if (tmp_assign_source_141 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[162], tmp_assign_source_141);
    }
    {
        PyObject *tmp_assign_source_142;
        PyObject *tmp_import_name_from_132;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_132 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_132)) {
            tmp_assign_source_142 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_132,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[163],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_142 = IMPORT_NAME(tmp_import_name_from_132, mod_consts[163]);
        }

        if (tmp_assign_source_142 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[163], tmp_assign_source_142);
    }
    {
        PyObject *tmp_assign_source_143;
        PyObject *tmp_import_name_from_133;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_133 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_133)) {
            tmp_assign_source_143 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_133,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[164],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_143 = IMPORT_NAME(tmp_import_name_from_133, mod_consts[164]);
        }

        if (tmp_assign_source_143 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[164], tmp_assign_source_143);
    }
    {
        PyObject *tmp_assign_source_144;
        PyObject *tmp_import_name_from_134;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_134 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_134)) {
            tmp_assign_source_144 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_134,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[165],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_144 = IMPORT_NAME(tmp_import_name_from_134, mod_consts[165]);
        }

        if (tmp_assign_source_144 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[165], tmp_assign_source_144);
    }
    {
        PyObject *tmp_assign_source_145;
        PyObject *tmp_import_name_from_135;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_135 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_135)) {
            tmp_assign_source_145 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_135,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[166],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_145 = IMPORT_NAME(tmp_import_name_from_135, mod_consts[166]);
        }

        if (tmp_assign_source_145 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[166], tmp_assign_source_145);
    }
    {
        PyObject *tmp_assign_source_146;
        PyObject *tmp_import_name_from_136;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_136 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_136)) {
            tmp_assign_source_146 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_136,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[167],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_146 = IMPORT_NAME(tmp_import_name_from_136, mod_consts[167]);
        }

        if (tmp_assign_source_146 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[167], tmp_assign_source_146);
    }
    {
        PyObject *tmp_assign_source_147;
        PyObject *tmp_import_name_from_137;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_137 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_137)) {
            tmp_assign_source_147 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_137,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[168],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_147 = IMPORT_NAME(tmp_import_name_from_137, mod_consts[168]);
        }

        if (tmp_assign_source_147 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[168], tmp_assign_source_147);
    }
    {
        PyObject *tmp_assign_source_148;
        PyObject *tmp_import_name_from_138;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_138 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_138)) {
            tmp_assign_source_148 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_138,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[169],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_148 = IMPORT_NAME(tmp_import_name_from_138, mod_consts[169]);
        }

        if (tmp_assign_source_148 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[169], tmp_assign_source_148);
    }
    {
        PyObject *tmp_assign_source_149;
        PyObject *tmp_import_name_from_139;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_139 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_139)) {
            tmp_assign_source_149 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_139,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[170],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_149 = IMPORT_NAME(tmp_import_name_from_139, mod_consts[170]);
        }

        if (tmp_assign_source_149 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[170], tmp_assign_source_149);
    }
    {
        PyObject *tmp_assign_source_150;
        PyObject *tmp_import_name_from_140;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_140 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_140)) {
            tmp_assign_source_150 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_140,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[171],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_150 = IMPORT_NAME(tmp_import_name_from_140, mod_consts[171]);
        }

        if (tmp_assign_source_150 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[171], tmp_assign_source_150);
    }
    {
        PyObject *tmp_assign_source_151;
        PyObject *tmp_import_name_from_141;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_141 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_141)) {
            tmp_assign_source_151 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_141,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[172],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_151 = IMPORT_NAME(tmp_import_name_from_141, mod_consts[172]);
        }

        if (tmp_assign_source_151 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[172], tmp_assign_source_151);
    }
    {
        PyObject *tmp_assign_source_152;
        PyObject *tmp_import_name_from_142;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_142 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_142)) {
            tmp_assign_source_152 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_142,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[173],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_152 = IMPORT_NAME(tmp_import_name_from_142, mod_consts[173]);
        }

        if (tmp_assign_source_152 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[173], tmp_assign_source_152);
    }
    {
        PyObject *tmp_assign_source_153;
        PyObject *tmp_import_name_from_143;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_143 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_143)) {
            tmp_assign_source_153 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_143,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[174],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_153 = IMPORT_NAME(tmp_import_name_from_143, mod_consts[174]);
        }

        if (tmp_assign_source_153 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[174], tmp_assign_source_153);
    }
    {
        PyObject *tmp_assign_source_154;
        PyObject *tmp_import_name_from_144;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_144 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_144)) {
            tmp_assign_source_154 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_144,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[175],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_154 = IMPORT_NAME(tmp_import_name_from_144, mod_consts[175]);
        }

        if (tmp_assign_source_154 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[175], tmp_assign_source_154);
    }
    {
        PyObject *tmp_assign_source_155;
        PyObject *tmp_import_name_from_145;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_145 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_145)) {
            tmp_assign_source_155 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_145,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[176],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_155 = IMPORT_NAME(tmp_import_name_from_145, mod_consts[176]);
        }

        if (tmp_assign_source_155 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[176], tmp_assign_source_155);
    }
    {
        PyObject *tmp_assign_source_156;
        PyObject *tmp_import_name_from_146;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_146 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_146)) {
            tmp_assign_source_156 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_146,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[177],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_156 = IMPORT_NAME(tmp_import_name_from_146, mod_consts[177]);
        }

        if (tmp_assign_source_156 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[177], tmp_assign_source_156);
    }
    {
        PyObject *tmp_assign_source_157;
        PyObject *tmp_import_name_from_147;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_147 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_147)) {
            tmp_assign_source_157 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_147,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[178],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_157 = IMPORT_NAME(tmp_import_name_from_147, mod_consts[178]);
        }

        if (tmp_assign_source_157 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[178], tmp_assign_source_157);
    }
    {
        PyObject *tmp_assign_source_158;
        PyObject *tmp_import_name_from_148;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_148 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_148)) {
            tmp_assign_source_158 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_148,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[179],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_158 = IMPORT_NAME(tmp_import_name_from_148, mod_consts[179]);
        }

        if (tmp_assign_source_158 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[179], tmp_assign_source_158);
    }
    {
        PyObject *tmp_assign_source_159;
        PyObject *tmp_import_name_from_149;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_149 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_149)) {
            tmp_assign_source_159 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_149,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[180],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_159 = IMPORT_NAME(tmp_import_name_from_149, mod_consts[180]);
        }

        if (tmp_assign_source_159 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[180], tmp_assign_source_159);
    }
    {
        PyObject *tmp_assign_source_160;
        PyObject *tmp_import_name_from_150;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_150 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_150)) {
            tmp_assign_source_160 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_150,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[181],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_160 = IMPORT_NAME(tmp_import_name_from_150, mod_consts[181]);
        }

        if (tmp_assign_source_160 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[181], tmp_assign_source_160);
    }
    {
        PyObject *tmp_assign_source_161;
        PyObject *tmp_import_name_from_151;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_151 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_151)) {
            tmp_assign_source_161 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_151,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[182],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_161 = IMPORT_NAME(tmp_import_name_from_151, mod_consts[182]);
        }

        if (tmp_assign_source_161 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[182], tmp_assign_source_161);
    }
    {
        PyObject *tmp_assign_source_162;
        PyObject *tmp_import_name_from_152;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_152 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_152)) {
            tmp_assign_source_162 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_152,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[183],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_162 = IMPORT_NAME(tmp_import_name_from_152, mod_consts[183]);
        }

        if (tmp_assign_source_162 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[183], tmp_assign_source_162);
    }
    {
        PyObject *tmp_assign_source_163;
        PyObject *tmp_import_name_from_153;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_153 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_153)) {
            tmp_assign_source_163 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_153,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[184],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_163 = IMPORT_NAME(tmp_import_name_from_153, mod_consts[184]);
        }

        if (tmp_assign_source_163 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[184], tmp_assign_source_163);
    }
    {
        PyObject *tmp_assign_source_164;
        PyObject *tmp_import_name_from_154;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_154 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_154)) {
            tmp_assign_source_164 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_154,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[185],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_164 = IMPORT_NAME(tmp_import_name_from_154, mod_consts[185]);
        }

        if (tmp_assign_source_164 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[185], tmp_assign_source_164);
    }
    {
        PyObject *tmp_assign_source_165;
        PyObject *tmp_import_name_from_155;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_155 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_155)) {
            tmp_assign_source_165 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_155,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[186],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_165 = IMPORT_NAME(tmp_import_name_from_155, mod_consts[186]);
        }

        if (tmp_assign_source_165 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[186], tmp_assign_source_165);
    }
    {
        PyObject *tmp_assign_source_166;
        PyObject *tmp_import_name_from_156;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_156 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_156)) {
            tmp_assign_source_166 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_156,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[187],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_166 = IMPORT_NAME(tmp_import_name_from_156, mod_consts[187]);
        }

        if (tmp_assign_source_166 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[187], tmp_assign_source_166);
    }
    {
        PyObject *tmp_assign_source_167;
        PyObject *tmp_import_name_from_157;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_157 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_157)) {
            tmp_assign_source_167 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_157,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[188],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_167 = IMPORT_NAME(tmp_import_name_from_157, mod_consts[188]);
        }

        if (tmp_assign_source_167 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[188], tmp_assign_source_167);
    }
    {
        PyObject *tmp_assign_source_168;
        PyObject *tmp_import_name_from_158;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_158 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_158)) {
            tmp_assign_source_168 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_158,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[189],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_168 = IMPORT_NAME(tmp_import_name_from_158, mod_consts[189]);
        }

        if (tmp_assign_source_168 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[189], tmp_assign_source_168);
    }
    {
        PyObject *tmp_assign_source_169;
        PyObject *tmp_import_name_from_159;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_159 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_159)) {
            tmp_assign_source_169 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_159,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[190],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_169 = IMPORT_NAME(tmp_import_name_from_159, mod_consts[190]);
        }

        if (tmp_assign_source_169 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[190], tmp_assign_source_169);
    }
    {
        PyObject *tmp_assign_source_170;
        PyObject *tmp_import_name_from_160;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_160 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_160)) {
            tmp_assign_source_170 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_160,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[191],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_170 = IMPORT_NAME(tmp_import_name_from_160, mod_consts[191]);
        }

        if (tmp_assign_source_170 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[191], tmp_assign_source_170);
    }
    {
        PyObject *tmp_assign_source_171;
        PyObject *tmp_import_name_from_161;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_161 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_161)) {
            tmp_assign_source_171 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_161,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[192],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_171 = IMPORT_NAME(tmp_import_name_from_161, mod_consts[192]);
        }

        if (tmp_assign_source_171 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[192], tmp_assign_source_171);
    }
    {
        PyObject *tmp_assign_source_172;
        PyObject *tmp_import_name_from_162;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_162 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_162)) {
            tmp_assign_source_172 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_162,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[193],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_172 = IMPORT_NAME(tmp_import_name_from_162, mod_consts[193]);
        }

        if (tmp_assign_source_172 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[193], tmp_assign_source_172);
    }
    {
        PyObject *tmp_assign_source_173;
        PyObject *tmp_import_name_from_163;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_163 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_163)) {
            tmp_assign_source_173 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_163,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[194],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_173 = IMPORT_NAME(tmp_import_name_from_163, mod_consts[194]);
        }

        if (tmp_assign_source_173 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[194], tmp_assign_source_173);
    }
    {
        PyObject *tmp_assign_source_174;
        PyObject *tmp_import_name_from_164;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_164 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_164)) {
            tmp_assign_source_174 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_164,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[195],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_174 = IMPORT_NAME(tmp_import_name_from_164, mod_consts[195]);
        }

        if (tmp_assign_source_174 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[195], tmp_assign_source_174);
    }
    {
        PyObject *tmp_assign_source_175;
        PyObject *tmp_import_name_from_165;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_165 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_165)) {
            tmp_assign_source_175 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_165,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[196],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_175 = IMPORT_NAME(tmp_import_name_from_165, mod_consts[196]);
        }

        if (tmp_assign_source_175 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[196], tmp_assign_source_175);
    }
    {
        PyObject *tmp_assign_source_176;
        PyObject *tmp_import_name_from_166;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_166 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_166)) {
            tmp_assign_source_176 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_166,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[197],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_176 = IMPORT_NAME(tmp_import_name_from_166, mod_consts[197]);
        }

        if (tmp_assign_source_176 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[197], tmp_assign_source_176);
    }
    {
        PyObject *tmp_assign_source_177;
        PyObject *tmp_import_name_from_167;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_167 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_167)) {
            tmp_assign_source_177 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_167,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[198],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_177 = IMPORT_NAME(tmp_import_name_from_167, mod_consts[198]);
        }

        if (tmp_assign_source_177 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[198], tmp_assign_source_177);
    }
    {
        PyObject *tmp_assign_source_178;
        PyObject *tmp_import_name_from_168;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_168 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_168)) {
            tmp_assign_source_178 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_168,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[199],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_178 = IMPORT_NAME(tmp_import_name_from_168, mod_consts[199]);
        }

        if (tmp_assign_source_178 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[199], tmp_assign_source_178);
    }
    {
        PyObject *tmp_assign_source_179;
        PyObject *tmp_import_name_from_169;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_169 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_169)) {
            tmp_assign_source_179 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_169,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[200],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_179 = IMPORT_NAME(tmp_import_name_from_169, mod_consts[200]);
        }

        if (tmp_assign_source_179 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[200], tmp_assign_source_179);
    }
    {
        PyObject *tmp_assign_source_180;
        PyObject *tmp_import_name_from_170;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_170 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_170)) {
            tmp_assign_source_180 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_170,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[201],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_180 = IMPORT_NAME(tmp_import_name_from_170, mod_consts[201]);
        }

        if (tmp_assign_source_180 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[201], tmp_assign_source_180);
    }
    {
        PyObject *tmp_assign_source_181;
        PyObject *tmp_import_name_from_171;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_171 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_171)) {
            tmp_assign_source_181 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_171,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[202],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_181 = IMPORT_NAME(tmp_import_name_from_171, mod_consts[202]);
        }

        if (tmp_assign_source_181 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[202], tmp_assign_source_181);
    }
    {
        PyObject *tmp_assign_source_182;
        PyObject *tmp_import_name_from_172;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_172 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_172)) {
            tmp_assign_source_182 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_172,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[203],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_182 = IMPORT_NAME(tmp_import_name_from_172, mod_consts[203]);
        }

        if (tmp_assign_source_182 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[203], tmp_assign_source_182);
    }
    {
        PyObject *tmp_assign_source_183;
        PyObject *tmp_import_name_from_173;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_173 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_173)) {
            tmp_assign_source_183 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_173,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[204],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_183 = IMPORT_NAME(tmp_import_name_from_173, mod_consts[204]);
        }

        if (tmp_assign_source_183 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[204], tmp_assign_source_183);
    }
    {
        PyObject *tmp_assign_source_184;
        PyObject *tmp_import_name_from_174;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_174 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_174)) {
            tmp_assign_source_184 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_174,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[205],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_184 = IMPORT_NAME(tmp_import_name_from_174, mod_consts[205]);
        }

        if (tmp_assign_source_184 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[205], tmp_assign_source_184);
    }
    {
        PyObject *tmp_assign_source_185;
        PyObject *tmp_import_name_from_175;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_175 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_175)) {
            tmp_assign_source_185 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_175,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[206],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_185 = IMPORT_NAME(tmp_import_name_from_175, mod_consts[206]);
        }

        if (tmp_assign_source_185 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[206], tmp_assign_source_185);
    }
    {
        PyObject *tmp_assign_source_186;
        PyObject *tmp_import_name_from_176;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_176 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_176)) {
            tmp_assign_source_186 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_176,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[207],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_186 = IMPORT_NAME(tmp_import_name_from_176, mod_consts[207]);
        }

        if (tmp_assign_source_186 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[207], tmp_assign_source_186);
    }
    {
        PyObject *tmp_assign_source_187;
        PyObject *tmp_import_name_from_177;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_177 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_177)) {
            tmp_assign_source_187 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_177,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[208],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_187 = IMPORT_NAME(tmp_import_name_from_177, mod_consts[208]);
        }

        if (tmp_assign_source_187 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[208], tmp_assign_source_187);
    }
    {
        PyObject *tmp_assign_source_188;
        PyObject *tmp_import_name_from_178;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_178 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_178)) {
            tmp_assign_source_188 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_178,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[209],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_188 = IMPORT_NAME(tmp_import_name_from_178, mod_consts[209]);
        }

        if (tmp_assign_source_188 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[209], tmp_assign_source_188);
    }
    {
        PyObject *tmp_assign_source_189;
        PyObject *tmp_import_name_from_179;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_179 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_179)) {
            tmp_assign_source_189 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_179,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[210],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_189 = IMPORT_NAME(tmp_import_name_from_179, mod_consts[210]);
        }

        if (tmp_assign_source_189 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[210], tmp_assign_source_189);
    }
    {
        PyObject *tmp_assign_source_190;
        PyObject *tmp_import_name_from_180;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_180 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_180)) {
            tmp_assign_source_190 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_180,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[211],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_190 = IMPORT_NAME(tmp_import_name_from_180, mod_consts[211]);
        }

        if (tmp_assign_source_190 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[211], tmp_assign_source_190);
    }
    {
        PyObject *tmp_assign_source_191;
        PyObject *tmp_import_name_from_181;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_181 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_181)) {
            tmp_assign_source_191 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_181,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[212],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_191 = IMPORT_NAME(tmp_import_name_from_181, mod_consts[212]);
        }

        if (tmp_assign_source_191 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[212], tmp_assign_source_191);
    }
    {
        PyObject *tmp_assign_source_192;
        PyObject *tmp_import_name_from_182;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_182 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_182)) {
            tmp_assign_source_192 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_182,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[213],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_192 = IMPORT_NAME(tmp_import_name_from_182, mod_consts[213]);
        }

        if (tmp_assign_source_192 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[213], tmp_assign_source_192);
    }
    {
        PyObject *tmp_assign_source_193;
        PyObject *tmp_import_name_from_183;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_183 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_183)) {
            tmp_assign_source_193 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_183,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[214],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_193 = IMPORT_NAME(tmp_import_name_from_183, mod_consts[214]);
        }

        if (tmp_assign_source_193 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[214], tmp_assign_source_193);
    }
    {
        PyObject *tmp_assign_source_194;
        PyObject *tmp_import_name_from_184;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_184 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_184)) {
            tmp_assign_source_194 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_184,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[215],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_194 = IMPORT_NAME(tmp_import_name_from_184, mod_consts[215]);
        }

        if (tmp_assign_source_194 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[215], tmp_assign_source_194);
    }
    {
        PyObject *tmp_assign_source_195;
        PyObject *tmp_import_name_from_185;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_185 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_185)) {
            tmp_assign_source_195 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_185,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[216],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_195 = IMPORT_NAME(tmp_import_name_from_185, mod_consts[216]);
        }

        if (tmp_assign_source_195 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[216], tmp_assign_source_195);
    }
    {
        PyObject *tmp_assign_source_196;
        PyObject *tmp_import_name_from_186;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_186 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_186)) {
            tmp_assign_source_196 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_186,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[217],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_196 = IMPORT_NAME(tmp_import_name_from_186, mod_consts[217]);
        }

        if (tmp_assign_source_196 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[217], tmp_assign_source_196);
    }
    {
        PyObject *tmp_assign_source_197;
        PyObject *tmp_import_name_from_187;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_187 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_187)) {
            tmp_assign_source_197 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_187,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[218],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_197 = IMPORT_NAME(tmp_import_name_from_187, mod_consts[218]);
        }

        if (tmp_assign_source_197 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[218], tmp_assign_source_197);
    }
    {
        PyObject *tmp_assign_source_198;
        PyObject *tmp_import_name_from_188;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_188 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_188)) {
            tmp_assign_source_198 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_188,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[219],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_198 = IMPORT_NAME(tmp_import_name_from_188, mod_consts[219]);
        }

        if (tmp_assign_source_198 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[219], tmp_assign_source_198);
    }
    {
        PyObject *tmp_assign_source_199;
        PyObject *tmp_import_name_from_189;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_189 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_189)) {
            tmp_assign_source_199 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_189,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[220],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_199 = IMPORT_NAME(tmp_import_name_from_189, mod_consts[220]);
        }

        if (tmp_assign_source_199 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[220], tmp_assign_source_199);
    }
    {
        PyObject *tmp_assign_source_200;
        PyObject *tmp_import_name_from_190;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_190 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_190)) {
            tmp_assign_source_200 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_190,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[221],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_200 = IMPORT_NAME(tmp_import_name_from_190, mod_consts[221]);
        }

        if (tmp_assign_source_200 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[221], tmp_assign_source_200);
    }
    {
        PyObject *tmp_assign_source_201;
        PyObject *tmp_import_name_from_191;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_191 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_191)) {
            tmp_assign_source_201 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_191,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[222],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_201 = IMPORT_NAME(tmp_import_name_from_191, mod_consts[222]);
        }

        if (tmp_assign_source_201 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[222], tmp_assign_source_201);
    }
    {
        PyObject *tmp_assign_source_202;
        PyObject *tmp_import_name_from_192;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_192 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_192)) {
            tmp_assign_source_202 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_192,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[223],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_202 = IMPORT_NAME(tmp_import_name_from_192, mod_consts[223]);
        }

        if (tmp_assign_source_202 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[223], tmp_assign_source_202);
    }
    {
        PyObject *tmp_assign_source_203;
        PyObject *tmp_import_name_from_193;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_193 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_193)) {
            tmp_assign_source_203 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_193,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[224],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_203 = IMPORT_NAME(tmp_import_name_from_193, mod_consts[224]);
        }

        if (tmp_assign_source_203 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[224], tmp_assign_source_203);
    }
    {
        PyObject *tmp_assign_source_204;
        PyObject *tmp_import_name_from_194;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_194 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_194)) {
            tmp_assign_source_204 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_194,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[225],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_204 = IMPORT_NAME(tmp_import_name_from_194, mod_consts[225]);
        }

        if (tmp_assign_source_204 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[225], tmp_assign_source_204);
    }
    {
        PyObject *tmp_assign_source_205;
        PyObject *tmp_import_name_from_195;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_195 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_195)) {
            tmp_assign_source_205 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_195,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[226],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_205 = IMPORT_NAME(tmp_import_name_from_195, mod_consts[226]);
        }

        if (tmp_assign_source_205 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[226], tmp_assign_source_205);
    }
    {
        PyObject *tmp_assign_source_206;
        PyObject *tmp_import_name_from_196;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_196 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_196)) {
            tmp_assign_source_206 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_196,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[227],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_206 = IMPORT_NAME(tmp_import_name_from_196, mod_consts[227]);
        }

        if (tmp_assign_source_206 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[227], tmp_assign_source_206);
    }
    {
        PyObject *tmp_assign_source_207;
        PyObject *tmp_import_name_from_197;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_197 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_197)) {
            tmp_assign_source_207 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_197,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[228],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_207 = IMPORT_NAME(tmp_import_name_from_197, mod_consts[228]);
        }

        if (tmp_assign_source_207 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[228], tmp_assign_source_207);
    }
    {
        PyObject *tmp_assign_source_208;
        PyObject *tmp_import_name_from_198;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_198 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_198)) {
            tmp_assign_source_208 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_198,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[229],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_208 = IMPORT_NAME(tmp_import_name_from_198, mod_consts[229]);
        }

        if (tmp_assign_source_208 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[229], tmp_assign_source_208);
    }
    {
        PyObject *tmp_assign_source_209;
        PyObject *tmp_import_name_from_199;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_199 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_199)) {
            tmp_assign_source_209 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_199,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[230],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_209 = IMPORT_NAME(tmp_import_name_from_199, mod_consts[230]);
        }

        if (tmp_assign_source_209 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[230], tmp_assign_source_209);
    }
    {
        PyObject *tmp_assign_source_210;
        PyObject *tmp_import_name_from_200;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_200 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_200)) {
            tmp_assign_source_210 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_200,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[231],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_210 = IMPORT_NAME(tmp_import_name_from_200, mod_consts[231]);
        }

        if (tmp_assign_source_210 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[231], tmp_assign_source_210);
    }
    {
        PyObject *tmp_assign_source_211;
        PyObject *tmp_import_name_from_201;
        CHECK_OBJECT(tmp_import_from_6__module);
        tmp_import_name_from_201 = tmp_import_from_6__module;
        if (PyModule_Check(tmp_import_name_from_201)) {
            tmp_assign_source_211 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_201,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[232],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_211 = IMPORT_NAME(tmp_import_name_from_201, mod_consts[232]);
        }

        if (tmp_assign_source_211 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 40;

            goto try_except_handler_6;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[232], tmp_assign_source_211);
    }
    goto try_end_6;
    // Exception handler code:
    try_except_handler_6:;
    exception_keeper_type_6 = exception_type;
    exception_keeper_value_6 = exception_value;
    exception_keeper_tb_6 = exception_tb;
    exception_keeper_lineno_6 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_6__module);
    Py_DECREF(tmp_import_from_6__module);
    tmp_import_from_6__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_6;
    exception_value = exception_keeper_value_6;
    exception_tb = exception_keeper_tb_6;
    exception_lineno = exception_keeper_lineno_6;

    goto frame_exception_exit_1;
    // End of try:
    try_end_6:;
    CHECK_OBJECT(tmp_import_from_6__module);
    Py_DECREF(tmp_import_from_6__module);
    tmp_import_from_6__module = NULL;
    {
        PyObject *tmp_assign_source_212;
        PyObject *tmp_name_value_8;
        PyObject *tmp_globals_arg_value_8;
        PyObject *tmp_locals_arg_value_8;
        PyObject *tmp_fromlist_value_8;
        PyObject *tmp_level_value_8;
        tmp_name_value_8 = mod_consts[44];
        tmp_globals_arg_value_8 = (PyObject *)moduledict_mutagen$id3;
        tmp_locals_arg_value_8 = Py_None;
        tmp_fromlist_value_8 = mod_consts[233];
        tmp_level_value_8 = mod_consts[20];
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 56;
        tmp_assign_source_212 = IMPORT_MODULE5(tmp_name_value_8, tmp_globals_arg_value_8, tmp_locals_arg_value_8, tmp_fromlist_value_8, tmp_level_value_8);
        if (tmp_assign_source_212 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto frame_exception_exit_1;
        }
        assert(tmp_import_from_7__module == NULL);
        tmp_import_from_7__module = tmp_assign_source_212;
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_213;
        PyObject *tmp_import_name_from_202;
        CHECK_OBJECT(tmp_import_from_7__module);
        tmp_import_name_from_202 = tmp_import_from_7__module;
        if (PyModule_Check(tmp_import_name_from_202)) {
            tmp_assign_source_213 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_202,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[234],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_213 = IMPORT_NAME(tmp_import_name_from_202, mod_consts[234]);
        }

        if (tmp_assign_source_213 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto try_except_handler_7;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[234], tmp_assign_source_213);
    }
    {
        PyObject *tmp_assign_source_214;
        PyObject *tmp_import_name_from_203;
        CHECK_OBJECT(tmp_import_from_7__module);
        tmp_import_name_from_203 = tmp_import_from_7__module;
        if (PyModule_Check(tmp_import_name_from_203)) {
            tmp_assign_source_214 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_203,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[235],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_214 = IMPORT_NAME(tmp_import_name_from_203, mod_consts[235]);
        }

        if (tmp_assign_source_214 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto try_except_handler_7;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[235], tmp_assign_source_214);
    }
    {
        PyObject *tmp_assign_source_215;
        PyObject *tmp_import_name_from_204;
        CHECK_OBJECT(tmp_import_from_7__module);
        tmp_import_name_from_204 = tmp_import_from_7__module;
        if (PyModule_Check(tmp_import_name_from_204)) {
            tmp_assign_source_215 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_204,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[236],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_215 = IMPORT_NAME(tmp_import_name_from_204, mod_consts[236]);
        }

        if (tmp_assign_source_215 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto try_except_handler_7;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[236], tmp_assign_source_215);
    }
    {
        PyObject *tmp_assign_source_216;
        PyObject *tmp_import_name_from_205;
        CHECK_OBJECT(tmp_import_from_7__module);
        tmp_import_name_from_205 = tmp_import_from_7__module;
        if (PyModule_Check(tmp_import_name_from_205)) {
            tmp_assign_source_216 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_205,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[237],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_216 = IMPORT_NAME(tmp_import_name_from_205, mod_consts[237]);
        }

        if (tmp_assign_source_216 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto try_except_handler_7;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[237], tmp_assign_source_216);
    }
    {
        PyObject *tmp_assign_source_217;
        PyObject *tmp_import_name_from_206;
        CHECK_OBJECT(tmp_import_from_7__module);
        tmp_import_name_from_206 = tmp_import_from_7__module;
        if (PyModule_Check(tmp_import_name_from_206)) {
            tmp_assign_source_217 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_206,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[238],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_217 = IMPORT_NAME(tmp_import_name_from_206, mod_consts[238]);
        }

        if (tmp_assign_source_217 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto try_except_handler_7;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[238], tmp_assign_source_217);
    }
    {
        PyObject *tmp_assign_source_218;
        PyObject *tmp_import_name_from_207;
        CHECK_OBJECT(tmp_import_from_7__module);
        tmp_import_name_from_207 = tmp_import_from_7__module;
        if (PyModule_Check(tmp_import_name_from_207)) {
            tmp_assign_source_218 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_207,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[239],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_218 = IMPORT_NAME(tmp_import_name_from_207, mod_consts[239]);
        }

        if (tmp_assign_source_218 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto try_except_handler_7;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[239], tmp_assign_source_218);
    }
    {
        PyObject *tmp_assign_source_219;
        PyObject *tmp_import_name_from_208;
        CHECK_OBJECT(tmp_import_from_7__module);
        tmp_import_name_from_208 = tmp_import_from_7__module;
        if (PyModule_Check(tmp_import_name_from_208)) {
            tmp_assign_source_219 = IMPORT_NAME_OR_MODULE(
                tmp_import_name_from_208,
                (PyObject *)moduledict_mutagen$id3,
                mod_consts[240],
                mod_consts[12]
            );
        } else {
            tmp_assign_source_219 = IMPORT_NAME(tmp_import_name_from_208, mod_consts[240]);
        }

        if (tmp_assign_source_219 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 56;

            goto try_except_handler_7;
        }
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[241], tmp_assign_source_219);
    }
    goto try_end_7;
    // Exception handler code:
    try_except_handler_7:;
    exception_keeper_type_7 = exception_type;
    exception_keeper_value_7 = exception_value;
    exception_keeper_tb_7 = exception_tb;
    exception_keeper_lineno_7 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    CHECK_OBJECT(tmp_import_from_7__module);
    Py_DECREF(tmp_import_from_7__module);
    tmp_import_from_7__module = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_7;
    exception_value = exception_keeper_value_7;
    exception_tb = exception_keeper_tb_7;
    exception_lineno = exception_keeper_lineno_7;

    goto frame_exception_exit_1;
    // End of try:
    try_end_7:;
    CHECK_OBJECT(tmp_import_from_7__module);
    Py_DECREF(tmp_import_from_7__module);
    tmp_import_from_7__module = NULL;
    {
        PyObject *tmp_assign_source_220;
        tmp_assign_source_220 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[21]);

        if (unlikely(tmp_assign_source_220 == NULL)) {
            tmp_assign_source_220 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[21]);
        }

        if (tmp_assign_source_220 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 61;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[242], tmp_assign_source_220);
    }
    {
        PyObject *tmp_mvar_value_1;
        tmp_mvar_value_1 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[21]);

        if (unlikely(tmp_mvar_value_1 == NULL)) {
            tmp_mvar_value_1 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[21]);
        }

        if (tmp_mvar_value_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 64;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_2;
        tmp_mvar_value_2 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[22]);

        if (unlikely(tmp_mvar_value_2 == NULL)) {
            tmp_mvar_value_2 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[22]);
        }

        if (tmp_mvar_value_2 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 64;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_3;
        tmp_mvar_value_3 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[23]);

        if (unlikely(tmp_mvar_value_3 == NULL)) {
            tmp_mvar_value_3 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[23]);
        }

        if (tmp_mvar_value_3 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 64;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_4;
        tmp_mvar_value_4 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[24]);

        if (unlikely(tmp_mvar_value_4 == NULL)) {
            tmp_mvar_value_4 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[24]);
        }

        if (tmp_mvar_value_4 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 64;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_5;
        tmp_mvar_value_5 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[27]);

        if (unlikely(tmp_mvar_value_5 == NULL)) {
            tmp_mvar_value_5 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[27]);
        }

        if (tmp_mvar_value_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 64;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_6;
        tmp_mvar_value_6 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[28]);

        if (unlikely(tmp_mvar_value_6 == NULL)) {
            tmp_mvar_value_6 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[28]);
        }

        if (tmp_mvar_value_6 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 64;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_7;
        tmp_mvar_value_7 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[29]);

        if (unlikely(tmp_mvar_value_7 == NULL)) {
            tmp_mvar_value_7 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[29]);
        }

        if (tmp_mvar_value_7 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 64;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_8;
        tmp_mvar_value_8 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[30]);

        if (unlikely(tmp_mvar_value_8 == NULL)) {
            tmp_mvar_value_8 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[30]);
        }

        if (tmp_mvar_value_8 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 65;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_9;
        tmp_mvar_value_9 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[33]);

        if (unlikely(tmp_mvar_value_9 == NULL)) {
            tmp_mvar_value_9 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[33]);
        }

        if (tmp_mvar_value_9 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 65;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_10;
        tmp_mvar_value_10 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[34]);

        if (unlikely(tmp_mvar_value_10 == NULL)) {
            tmp_mvar_value_10 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[34]);
        }

        if (tmp_mvar_value_10 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 65;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_11;
        tmp_mvar_value_11 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[35]);

        if (unlikely(tmp_mvar_value_11 == NULL)) {
            tmp_mvar_value_11 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[35]);
        }

        if (tmp_mvar_value_11 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 65;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_12;
        tmp_mvar_value_12 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[36]);

        if (unlikely(tmp_mvar_value_12 == NULL)) {
            tmp_mvar_value_12 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[36]);
        }

        if (tmp_mvar_value_12 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 65;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_13;
        tmp_mvar_value_13 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[37]);

        if (unlikely(tmp_mvar_value_13 == NULL)) {
            tmp_mvar_value_13 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[37]);
        }

        if (tmp_mvar_value_13 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 65;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_14;
        tmp_mvar_value_14 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[38]);

        if (unlikely(tmp_mvar_value_14 == NULL)) {
            tmp_mvar_value_14 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[38]);
        }

        if (tmp_mvar_value_14 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 65;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_15;
        tmp_mvar_value_15 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[39]);

        if (unlikely(tmp_mvar_value_15 == NULL)) {
            tmp_mvar_value_15 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[39]);
        }

        if (tmp_mvar_value_15 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 66;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_16;
        tmp_mvar_value_16 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[40]);

        if (unlikely(tmp_mvar_value_16 == NULL)) {
            tmp_mvar_value_16 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[40]);
        }

        if (tmp_mvar_value_16 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 66;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_17;
        tmp_mvar_value_17 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[41]);

        if (unlikely(tmp_mvar_value_17 == NULL)) {
            tmp_mvar_value_17 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[41]);
        }

        if (tmp_mvar_value_17 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 66;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_18;
        tmp_mvar_value_18 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[42]);

        if (unlikely(tmp_mvar_value_18 == NULL)) {
            tmp_mvar_value_18 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[42]);
        }

        if (tmp_mvar_value_18 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 66;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_19;
        tmp_mvar_value_19 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[43]);

        if (unlikely(tmp_mvar_value_19 == NULL)) {
            tmp_mvar_value_19 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[43]);
        }

        if (tmp_mvar_value_19 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 67;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_20;
        tmp_mvar_value_20 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[46]);

        if (unlikely(tmp_mvar_value_20 == NULL)) {
            tmp_mvar_value_20 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[46]);
        }

        if (tmp_mvar_value_20 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 67;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_21;
        tmp_mvar_value_21 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[47]);

        if (unlikely(tmp_mvar_value_21 == NULL)) {
            tmp_mvar_value_21 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[47]);
        }

        if (tmp_mvar_value_21 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 67;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_22;
        tmp_mvar_value_22 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[48]);

        if (unlikely(tmp_mvar_value_22 == NULL)) {
            tmp_mvar_value_22 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[48]);
        }

        if (tmp_mvar_value_22 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 67;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_23;
        tmp_mvar_value_23 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[51]);

        if (unlikely(tmp_mvar_value_23 == NULL)) {
            tmp_mvar_value_23 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[51]);
        }

        if (tmp_mvar_value_23 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 68;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_24;
        tmp_mvar_value_24 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[52]);

        if (unlikely(tmp_mvar_value_24 == NULL)) {
            tmp_mvar_value_24 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[52]);
        }

        if (tmp_mvar_value_24 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 68;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_25;
        tmp_mvar_value_25 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[55]);

        if (unlikely(tmp_mvar_value_25 == NULL)) {
            tmp_mvar_value_25 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[55]);
        }

        if (tmp_mvar_value_25 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 68;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_26;
        tmp_mvar_value_26 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[234]);

        if (unlikely(tmp_mvar_value_26 == NULL)) {
            tmp_mvar_value_26 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[234]);
        }

        if (tmp_mvar_value_26 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 68;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_27;
        tmp_mvar_value_27 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[235]);

        if (unlikely(tmp_mvar_value_27 == NULL)) {
            tmp_mvar_value_27 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[235]);
        }

        if (tmp_mvar_value_27 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 69;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_28;
        tmp_mvar_value_28 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[236]);

        if (unlikely(tmp_mvar_value_28 == NULL)) {
            tmp_mvar_value_28 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[236]);
        }

        if (tmp_mvar_value_28 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 69;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_29;
        tmp_mvar_value_29 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[237]);

        if (unlikely(tmp_mvar_value_29 == NULL)) {
            tmp_mvar_value_29 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[237]);
        }

        if (tmp_mvar_value_29 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 69;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_30;
        tmp_mvar_value_30 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[238]);

        if (unlikely(tmp_mvar_value_30 == NULL)) {
            tmp_mvar_value_30 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[238]);
        }

        if (tmp_mvar_value_30 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 69;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_31;
        tmp_mvar_value_31 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[239]);

        if (unlikely(tmp_mvar_value_31 == NULL)) {
            tmp_mvar_value_31 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[239]);
        }

        if (tmp_mvar_value_31 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 70;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_32;
        tmp_mvar_value_32 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[57]);

        if (unlikely(tmp_mvar_value_32 == NULL)) {
            tmp_mvar_value_32 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[57]);
        }

        if (tmp_mvar_value_32 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_33;
        tmp_mvar_value_33 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[58]);

        if (unlikely(tmp_mvar_value_33 == NULL)) {
            tmp_mvar_value_33 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[58]);
        }

        if (tmp_mvar_value_33 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_34;
        tmp_mvar_value_34 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[59]);

        if (unlikely(tmp_mvar_value_34 == NULL)) {
            tmp_mvar_value_34 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[59]);
        }

        if (tmp_mvar_value_34 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_35;
        tmp_mvar_value_35 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[60]);

        if (unlikely(tmp_mvar_value_35 == NULL)) {
            tmp_mvar_value_35 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[60]);
        }

        if (tmp_mvar_value_35 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_36;
        tmp_mvar_value_36 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[61]);

        if (unlikely(tmp_mvar_value_36 == NULL)) {
            tmp_mvar_value_36 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[61]);
        }

        if (tmp_mvar_value_36 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_37;
        tmp_mvar_value_37 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[62]);

        if (unlikely(tmp_mvar_value_37 == NULL)) {
            tmp_mvar_value_37 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[62]);
        }

        if (tmp_mvar_value_37 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_38;
        tmp_mvar_value_38 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[63]);

        if (unlikely(tmp_mvar_value_38 == NULL)) {
            tmp_mvar_value_38 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[63]);
        }

        if (tmp_mvar_value_38 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_39;
        tmp_mvar_value_39 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[64]);

        if (unlikely(tmp_mvar_value_39 == NULL)) {
            tmp_mvar_value_39 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[64]);
        }

        if (tmp_mvar_value_39 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_40;
        tmp_mvar_value_40 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[65]);

        if (unlikely(tmp_mvar_value_40 == NULL)) {
            tmp_mvar_value_40 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[65]);
        }

        if (tmp_mvar_value_40 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_41;
        tmp_mvar_value_41 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[66]);

        if (unlikely(tmp_mvar_value_41 == NULL)) {
            tmp_mvar_value_41 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[66]);
        }

        if (tmp_mvar_value_41 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_42;
        tmp_mvar_value_42 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[67]);

        if (unlikely(tmp_mvar_value_42 == NULL)) {
            tmp_mvar_value_42 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[67]);
        }

        if (tmp_mvar_value_42 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_43;
        tmp_mvar_value_43 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[68]);

        if (unlikely(tmp_mvar_value_43 == NULL)) {
            tmp_mvar_value_43 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[68]);
        }

        if (tmp_mvar_value_43 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_44;
        tmp_mvar_value_44 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[69]);

        if (unlikely(tmp_mvar_value_44 == NULL)) {
            tmp_mvar_value_44 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[69]);
        }

        if (tmp_mvar_value_44 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_45;
        tmp_mvar_value_45 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[70]);

        if (unlikely(tmp_mvar_value_45 == NULL)) {
            tmp_mvar_value_45 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[70]);
        }

        if (tmp_mvar_value_45 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 72;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_46;
        tmp_mvar_value_46 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[71]);

        if (unlikely(tmp_mvar_value_46 == NULL)) {
            tmp_mvar_value_46 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[71]);
        }

        if (tmp_mvar_value_46 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_47;
        tmp_mvar_value_47 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[72]);

        if (unlikely(tmp_mvar_value_47 == NULL)) {
            tmp_mvar_value_47 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[72]);
        }

        if (tmp_mvar_value_47 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_48;
        tmp_mvar_value_48 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[73]);

        if (unlikely(tmp_mvar_value_48 == NULL)) {
            tmp_mvar_value_48 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[73]);
        }

        if (tmp_mvar_value_48 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_49;
        tmp_mvar_value_49 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[74]);

        if (unlikely(tmp_mvar_value_49 == NULL)) {
            tmp_mvar_value_49 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[74]);
        }

        if (tmp_mvar_value_49 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_50;
        tmp_mvar_value_50 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[75]);

        if (unlikely(tmp_mvar_value_50 == NULL)) {
            tmp_mvar_value_50 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[75]);
        }

        if (tmp_mvar_value_50 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_51;
        tmp_mvar_value_51 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[76]);

        if (unlikely(tmp_mvar_value_51 == NULL)) {
            tmp_mvar_value_51 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[76]);
        }

        if (tmp_mvar_value_51 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_52;
        tmp_mvar_value_52 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[77]);

        if (unlikely(tmp_mvar_value_52 == NULL)) {
            tmp_mvar_value_52 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[77]);
        }

        if (tmp_mvar_value_52 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_53;
        tmp_mvar_value_53 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[78]);

        if (unlikely(tmp_mvar_value_53 == NULL)) {
            tmp_mvar_value_53 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[78]);
        }

        if (tmp_mvar_value_53 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_54;
        tmp_mvar_value_54 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[79]);

        if (unlikely(tmp_mvar_value_54 == NULL)) {
            tmp_mvar_value_54 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[79]);
        }

        if (tmp_mvar_value_54 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_55;
        tmp_mvar_value_55 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[80]);

        if (unlikely(tmp_mvar_value_55 == NULL)) {
            tmp_mvar_value_55 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[80]);
        }

        if (tmp_mvar_value_55 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_56;
        tmp_mvar_value_56 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[81]);

        if (unlikely(tmp_mvar_value_56 == NULL)) {
            tmp_mvar_value_56 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[81]);
        }

        if (tmp_mvar_value_56 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_57;
        tmp_mvar_value_57 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[82]);

        if (unlikely(tmp_mvar_value_57 == NULL)) {
            tmp_mvar_value_57 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[82]);
        }

        if (tmp_mvar_value_57 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_58;
        tmp_mvar_value_58 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[83]);

        if (unlikely(tmp_mvar_value_58 == NULL)) {
            tmp_mvar_value_58 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[83]);
        }

        if (tmp_mvar_value_58 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_59;
        tmp_mvar_value_59 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[84]);

        if (unlikely(tmp_mvar_value_59 == NULL)) {
            tmp_mvar_value_59 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[84]);
        }

        if (tmp_mvar_value_59 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 73;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_60;
        tmp_mvar_value_60 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[85]);

        if (unlikely(tmp_mvar_value_60 == NULL)) {
            tmp_mvar_value_60 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[85]);
        }

        if (tmp_mvar_value_60 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_61;
        tmp_mvar_value_61 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[86]);

        if (unlikely(tmp_mvar_value_61 == NULL)) {
            tmp_mvar_value_61 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[86]);
        }

        if (tmp_mvar_value_61 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_62;
        tmp_mvar_value_62 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[87]);

        if (unlikely(tmp_mvar_value_62 == NULL)) {
            tmp_mvar_value_62 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[87]);
        }

        if (tmp_mvar_value_62 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_63;
        tmp_mvar_value_63 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[88]);

        if (unlikely(tmp_mvar_value_63 == NULL)) {
            tmp_mvar_value_63 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[88]);
        }

        if (tmp_mvar_value_63 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_64;
        tmp_mvar_value_64 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[89]);

        if (unlikely(tmp_mvar_value_64 == NULL)) {
            tmp_mvar_value_64 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[89]);
        }

        if (tmp_mvar_value_64 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_65;
        tmp_mvar_value_65 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[90]);

        if (unlikely(tmp_mvar_value_65 == NULL)) {
            tmp_mvar_value_65 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[90]);
        }

        if (tmp_mvar_value_65 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_66;
        tmp_mvar_value_66 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[91]);

        if (unlikely(tmp_mvar_value_66 == NULL)) {
            tmp_mvar_value_66 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[91]);
        }

        if (tmp_mvar_value_66 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_67;
        tmp_mvar_value_67 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[92]);

        if (unlikely(tmp_mvar_value_67 == NULL)) {
            tmp_mvar_value_67 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[92]);
        }

        if (tmp_mvar_value_67 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_68;
        tmp_mvar_value_68 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[93]);

        if (unlikely(tmp_mvar_value_68 == NULL)) {
            tmp_mvar_value_68 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[93]);
        }

        if (tmp_mvar_value_68 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_69;
        tmp_mvar_value_69 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[94]);

        if (unlikely(tmp_mvar_value_69 == NULL)) {
            tmp_mvar_value_69 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[94]);
        }

        if (tmp_mvar_value_69 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_70;
        tmp_mvar_value_70 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[95]);

        if (unlikely(tmp_mvar_value_70 == NULL)) {
            tmp_mvar_value_70 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[95]);
        }

        if (tmp_mvar_value_70 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_71;
        tmp_mvar_value_71 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[96]);

        if (unlikely(tmp_mvar_value_71 == NULL)) {
            tmp_mvar_value_71 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[96]);
        }

        if (tmp_mvar_value_71 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_72;
        tmp_mvar_value_72 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[97]);

        if (unlikely(tmp_mvar_value_72 == NULL)) {
            tmp_mvar_value_72 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[97]);
        }

        if (tmp_mvar_value_72 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 74;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_73;
        tmp_mvar_value_73 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[98]);

        if (unlikely(tmp_mvar_value_73 == NULL)) {
            tmp_mvar_value_73 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[98]);
        }

        if (tmp_mvar_value_73 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_74;
        tmp_mvar_value_74 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[99]);

        if (unlikely(tmp_mvar_value_74 == NULL)) {
            tmp_mvar_value_74 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[99]);
        }

        if (tmp_mvar_value_74 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_75;
        tmp_mvar_value_75 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[100]);

        if (unlikely(tmp_mvar_value_75 == NULL)) {
            tmp_mvar_value_75 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[100]);
        }

        if (tmp_mvar_value_75 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_76;
        tmp_mvar_value_76 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[101]);

        if (unlikely(tmp_mvar_value_76 == NULL)) {
            tmp_mvar_value_76 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[101]);
        }

        if (tmp_mvar_value_76 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_77;
        tmp_mvar_value_77 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[102]);

        if (unlikely(tmp_mvar_value_77 == NULL)) {
            tmp_mvar_value_77 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[102]);
        }

        if (tmp_mvar_value_77 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_78;
        tmp_mvar_value_78 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[103]);

        if (unlikely(tmp_mvar_value_78 == NULL)) {
            tmp_mvar_value_78 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[103]);
        }

        if (tmp_mvar_value_78 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_79;
        tmp_mvar_value_79 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[104]);

        if (unlikely(tmp_mvar_value_79 == NULL)) {
            tmp_mvar_value_79 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[104]);
        }

        if (tmp_mvar_value_79 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_80;
        tmp_mvar_value_80 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[105]);

        if (unlikely(tmp_mvar_value_80 == NULL)) {
            tmp_mvar_value_80 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[105]);
        }

        if (tmp_mvar_value_80 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_81;
        tmp_mvar_value_81 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[106]);

        if (unlikely(tmp_mvar_value_81 == NULL)) {
            tmp_mvar_value_81 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[106]);
        }

        if (tmp_mvar_value_81 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_82;
        tmp_mvar_value_82 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[107]);

        if (unlikely(tmp_mvar_value_82 == NULL)) {
            tmp_mvar_value_82 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[107]);
        }

        if (tmp_mvar_value_82 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_83;
        tmp_mvar_value_83 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[108]);

        if (unlikely(tmp_mvar_value_83 == NULL)) {
            tmp_mvar_value_83 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[108]);
        }

        if (tmp_mvar_value_83 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_84;
        tmp_mvar_value_84 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[109]);

        if (unlikely(tmp_mvar_value_84 == NULL)) {
            tmp_mvar_value_84 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[109]);
        }

        if (tmp_mvar_value_84 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_85;
        tmp_mvar_value_85 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[110]);

        if (unlikely(tmp_mvar_value_85 == NULL)) {
            tmp_mvar_value_85 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[110]);
        }

        if (tmp_mvar_value_85 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_86;
        tmp_mvar_value_86 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[111]);

        if (unlikely(tmp_mvar_value_86 == NULL)) {
            tmp_mvar_value_86 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[111]);
        }

        if (tmp_mvar_value_86 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 75;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_87;
        tmp_mvar_value_87 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[112]);

        if (unlikely(tmp_mvar_value_87 == NULL)) {
            tmp_mvar_value_87 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[112]);
        }

        if (tmp_mvar_value_87 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_88;
        tmp_mvar_value_88 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[113]);

        if (unlikely(tmp_mvar_value_88 == NULL)) {
            tmp_mvar_value_88 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[113]);
        }

        if (tmp_mvar_value_88 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_89;
        tmp_mvar_value_89 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[114]);

        if (unlikely(tmp_mvar_value_89 == NULL)) {
            tmp_mvar_value_89 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[114]);
        }

        if (tmp_mvar_value_89 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_90;
        tmp_mvar_value_90 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[115]);

        if (unlikely(tmp_mvar_value_90 == NULL)) {
            tmp_mvar_value_90 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[115]);
        }

        if (tmp_mvar_value_90 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_91;
        tmp_mvar_value_91 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[116]);

        if (unlikely(tmp_mvar_value_91 == NULL)) {
            tmp_mvar_value_91 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[116]);
        }

        if (tmp_mvar_value_91 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_92;
        tmp_mvar_value_92 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[117]);

        if (unlikely(tmp_mvar_value_92 == NULL)) {
            tmp_mvar_value_92 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[117]);
        }

        if (tmp_mvar_value_92 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_93;
        tmp_mvar_value_93 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[118]);

        if (unlikely(tmp_mvar_value_93 == NULL)) {
            tmp_mvar_value_93 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[118]);
        }

        if (tmp_mvar_value_93 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_94;
        tmp_mvar_value_94 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[119]);

        if (unlikely(tmp_mvar_value_94 == NULL)) {
            tmp_mvar_value_94 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[119]);
        }

        if (tmp_mvar_value_94 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_95;
        tmp_mvar_value_95 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[120]);

        if (unlikely(tmp_mvar_value_95 == NULL)) {
            tmp_mvar_value_95 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[120]);
        }

        if (tmp_mvar_value_95 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_96;
        tmp_mvar_value_96 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[121]);

        if (unlikely(tmp_mvar_value_96 == NULL)) {
            tmp_mvar_value_96 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[121]);
        }

        if (tmp_mvar_value_96 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_97;
        tmp_mvar_value_97 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[122]);

        if (unlikely(tmp_mvar_value_97 == NULL)) {
            tmp_mvar_value_97 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[122]);
        }

        if (tmp_mvar_value_97 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_98;
        tmp_mvar_value_98 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[123]);

        if (unlikely(tmp_mvar_value_98 == NULL)) {
            tmp_mvar_value_98 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[123]);
        }

        if (tmp_mvar_value_98 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_99;
        tmp_mvar_value_99 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[124]);

        if (unlikely(tmp_mvar_value_99 == NULL)) {
            tmp_mvar_value_99 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[124]);
        }

        if (tmp_mvar_value_99 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_100;
        tmp_mvar_value_100 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[125]);

        if (unlikely(tmp_mvar_value_100 == NULL)) {
            tmp_mvar_value_100 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[125]);
        }

        if (tmp_mvar_value_100 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 76;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_101;
        tmp_mvar_value_101 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[126]);

        if (unlikely(tmp_mvar_value_101 == NULL)) {
            tmp_mvar_value_101 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[126]);
        }

        if (tmp_mvar_value_101 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_102;
        tmp_mvar_value_102 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[127]);

        if (unlikely(tmp_mvar_value_102 == NULL)) {
            tmp_mvar_value_102 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[127]);
        }

        if (tmp_mvar_value_102 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_103;
        tmp_mvar_value_103 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[128]);

        if (unlikely(tmp_mvar_value_103 == NULL)) {
            tmp_mvar_value_103 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[128]);
        }

        if (tmp_mvar_value_103 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_104;
        tmp_mvar_value_104 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[129]);

        if (unlikely(tmp_mvar_value_104 == NULL)) {
            tmp_mvar_value_104 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[129]);
        }

        if (tmp_mvar_value_104 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_105;
        tmp_mvar_value_105 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[130]);

        if (unlikely(tmp_mvar_value_105 == NULL)) {
            tmp_mvar_value_105 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[130]);
        }

        if (tmp_mvar_value_105 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_106;
        tmp_mvar_value_106 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[131]);

        if (unlikely(tmp_mvar_value_106 == NULL)) {
            tmp_mvar_value_106 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[131]);
        }

        if (tmp_mvar_value_106 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_107;
        tmp_mvar_value_107 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[132]);

        if (unlikely(tmp_mvar_value_107 == NULL)) {
            tmp_mvar_value_107 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[132]);
        }

        if (tmp_mvar_value_107 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_108;
        tmp_mvar_value_108 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[133]);

        if (unlikely(tmp_mvar_value_108 == NULL)) {
            tmp_mvar_value_108 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[133]);
        }

        if (tmp_mvar_value_108 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_109;
        tmp_mvar_value_109 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[134]);

        if (unlikely(tmp_mvar_value_109 == NULL)) {
            tmp_mvar_value_109 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[134]);
        }

        if (tmp_mvar_value_109 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_110;
        tmp_mvar_value_110 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[135]);

        if (unlikely(tmp_mvar_value_110 == NULL)) {
            tmp_mvar_value_110 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[135]);
        }

        if (tmp_mvar_value_110 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_111;
        tmp_mvar_value_111 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[136]);

        if (unlikely(tmp_mvar_value_111 == NULL)) {
            tmp_mvar_value_111 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[136]);
        }

        if (tmp_mvar_value_111 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_112;
        tmp_mvar_value_112 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[137]);

        if (unlikely(tmp_mvar_value_112 == NULL)) {
            tmp_mvar_value_112 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[137]);
        }

        if (tmp_mvar_value_112 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_113;
        tmp_mvar_value_113 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[138]);

        if (unlikely(tmp_mvar_value_113 == NULL)) {
            tmp_mvar_value_113 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[138]);
        }

        if (tmp_mvar_value_113 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 77;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_114;
        tmp_mvar_value_114 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[139]);

        if (unlikely(tmp_mvar_value_114 == NULL)) {
            tmp_mvar_value_114 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[139]);
        }

        if (tmp_mvar_value_114 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_115;
        tmp_mvar_value_115 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[140]);

        if (unlikely(tmp_mvar_value_115 == NULL)) {
            tmp_mvar_value_115 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[140]);
        }

        if (tmp_mvar_value_115 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_116;
        tmp_mvar_value_116 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[141]);

        if (unlikely(tmp_mvar_value_116 == NULL)) {
            tmp_mvar_value_116 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[141]);
        }

        if (tmp_mvar_value_116 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_117;
        tmp_mvar_value_117 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[142]);

        if (unlikely(tmp_mvar_value_117 == NULL)) {
            tmp_mvar_value_117 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[142]);
        }

        if (tmp_mvar_value_117 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_118;
        tmp_mvar_value_118 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[143]);

        if (unlikely(tmp_mvar_value_118 == NULL)) {
            tmp_mvar_value_118 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[143]);
        }

        if (tmp_mvar_value_118 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_119;
        tmp_mvar_value_119 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[144]);

        if (unlikely(tmp_mvar_value_119 == NULL)) {
            tmp_mvar_value_119 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[144]);
        }

        if (tmp_mvar_value_119 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_120;
        tmp_mvar_value_120 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[145]);

        if (unlikely(tmp_mvar_value_120 == NULL)) {
            tmp_mvar_value_120 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[145]);
        }

        if (tmp_mvar_value_120 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_121;
        tmp_mvar_value_121 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[146]);

        if (unlikely(tmp_mvar_value_121 == NULL)) {
            tmp_mvar_value_121 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[146]);
        }

        if (tmp_mvar_value_121 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_122;
        tmp_mvar_value_122 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[147]);

        if (unlikely(tmp_mvar_value_122 == NULL)) {
            tmp_mvar_value_122 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[147]);
        }

        if (tmp_mvar_value_122 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_123;
        tmp_mvar_value_123 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[148]);

        if (unlikely(tmp_mvar_value_123 == NULL)) {
            tmp_mvar_value_123 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[148]);
        }

        if (tmp_mvar_value_123 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_124;
        tmp_mvar_value_124 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[149]);

        if (unlikely(tmp_mvar_value_124 == NULL)) {
            tmp_mvar_value_124 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[149]);
        }

        if (tmp_mvar_value_124 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_125;
        tmp_mvar_value_125 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[150]);

        if (unlikely(tmp_mvar_value_125 == NULL)) {
            tmp_mvar_value_125 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[150]);
        }

        if (tmp_mvar_value_125 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_126;
        tmp_mvar_value_126 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[151]);

        if (unlikely(tmp_mvar_value_126 == NULL)) {
            tmp_mvar_value_126 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[151]);
        }

        if (tmp_mvar_value_126 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 78;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_127;
        tmp_mvar_value_127 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[152]);

        if (unlikely(tmp_mvar_value_127 == NULL)) {
            tmp_mvar_value_127 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[152]);
        }

        if (tmp_mvar_value_127 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_128;
        tmp_mvar_value_128 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[153]);

        if (unlikely(tmp_mvar_value_128 == NULL)) {
            tmp_mvar_value_128 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[153]);
        }

        if (tmp_mvar_value_128 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_129;
        tmp_mvar_value_129 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[154]);

        if (unlikely(tmp_mvar_value_129 == NULL)) {
            tmp_mvar_value_129 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[154]);
        }

        if (tmp_mvar_value_129 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_130;
        tmp_mvar_value_130 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[155]);

        if (unlikely(tmp_mvar_value_130 == NULL)) {
            tmp_mvar_value_130 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[155]);
        }

        if (tmp_mvar_value_130 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_131;
        tmp_mvar_value_131 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[156]);

        if (unlikely(tmp_mvar_value_131 == NULL)) {
            tmp_mvar_value_131 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[156]);
        }

        if (tmp_mvar_value_131 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_132;
        tmp_mvar_value_132 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[157]);

        if (unlikely(tmp_mvar_value_132 == NULL)) {
            tmp_mvar_value_132 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[157]);
        }

        if (tmp_mvar_value_132 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_133;
        tmp_mvar_value_133 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[158]);

        if (unlikely(tmp_mvar_value_133 == NULL)) {
            tmp_mvar_value_133 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[158]);
        }

        if (tmp_mvar_value_133 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_134;
        tmp_mvar_value_134 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[159]);

        if (unlikely(tmp_mvar_value_134 == NULL)) {
            tmp_mvar_value_134 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[159]);
        }

        if (tmp_mvar_value_134 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_135;
        tmp_mvar_value_135 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[160]);

        if (unlikely(tmp_mvar_value_135 == NULL)) {
            tmp_mvar_value_135 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[160]);
        }

        if (tmp_mvar_value_135 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_136;
        tmp_mvar_value_136 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[161]);

        if (unlikely(tmp_mvar_value_136 == NULL)) {
            tmp_mvar_value_136 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[161]);
        }

        if (tmp_mvar_value_136 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_137;
        tmp_mvar_value_137 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[162]);

        if (unlikely(tmp_mvar_value_137 == NULL)) {
            tmp_mvar_value_137 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[162]);
        }

        if (tmp_mvar_value_137 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_138;
        tmp_mvar_value_138 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[163]);

        if (unlikely(tmp_mvar_value_138 == NULL)) {
            tmp_mvar_value_138 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[163]);
        }

        if (tmp_mvar_value_138 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_139;
        tmp_mvar_value_139 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[164]);

        if (unlikely(tmp_mvar_value_139 == NULL)) {
            tmp_mvar_value_139 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[164]);
        }

        if (tmp_mvar_value_139 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_140;
        tmp_mvar_value_140 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[165]);

        if (unlikely(tmp_mvar_value_140 == NULL)) {
            tmp_mvar_value_140 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[165]);
        }

        if (tmp_mvar_value_140 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 79;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_141;
        tmp_mvar_value_141 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[166]);

        if (unlikely(tmp_mvar_value_141 == NULL)) {
            tmp_mvar_value_141 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[166]);
        }

        if (tmp_mvar_value_141 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_142;
        tmp_mvar_value_142 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[167]);

        if (unlikely(tmp_mvar_value_142 == NULL)) {
            tmp_mvar_value_142 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[167]);
        }

        if (tmp_mvar_value_142 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_143;
        tmp_mvar_value_143 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[168]);

        if (unlikely(tmp_mvar_value_143 == NULL)) {
            tmp_mvar_value_143 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[168]);
        }

        if (tmp_mvar_value_143 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_144;
        tmp_mvar_value_144 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[169]);

        if (unlikely(tmp_mvar_value_144 == NULL)) {
            tmp_mvar_value_144 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[169]);
        }

        if (tmp_mvar_value_144 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_145;
        tmp_mvar_value_145 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[170]);

        if (unlikely(tmp_mvar_value_145 == NULL)) {
            tmp_mvar_value_145 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[170]);
        }

        if (tmp_mvar_value_145 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_146;
        tmp_mvar_value_146 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[171]);

        if (unlikely(tmp_mvar_value_146 == NULL)) {
            tmp_mvar_value_146 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[171]);
        }

        if (tmp_mvar_value_146 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_147;
        tmp_mvar_value_147 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[172]);

        if (unlikely(tmp_mvar_value_147 == NULL)) {
            tmp_mvar_value_147 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[172]);
        }

        if (tmp_mvar_value_147 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_148;
        tmp_mvar_value_148 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[173]);

        if (unlikely(tmp_mvar_value_148 == NULL)) {
            tmp_mvar_value_148 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[173]);
        }

        if (tmp_mvar_value_148 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_149;
        tmp_mvar_value_149 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[174]);

        if (unlikely(tmp_mvar_value_149 == NULL)) {
            tmp_mvar_value_149 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[174]);
        }

        if (tmp_mvar_value_149 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_150;
        tmp_mvar_value_150 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[175]);

        if (unlikely(tmp_mvar_value_150 == NULL)) {
            tmp_mvar_value_150 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[175]);
        }

        if (tmp_mvar_value_150 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_151;
        tmp_mvar_value_151 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[176]);

        if (unlikely(tmp_mvar_value_151 == NULL)) {
            tmp_mvar_value_151 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[176]);
        }

        if (tmp_mvar_value_151 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_152;
        tmp_mvar_value_152 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[177]);

        if (unlikely(tmp_mvar_value_152 == NULL)) {
            tmp_mvar_value_152 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[177]);
        }

        if (tmp_mvar_value_152 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_153;
        tmp_mvar_value_153 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[178]);

        if (unlikely(tmp_mvar_value_153 == NULL)) {
            tmp_mvar_value_153 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[178]);
        }

        if (tmp_mvar_value_153 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_154;
        tmp_mvar_value_154 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[179]);

        if (unlikely(tmp_mvar_value_154 == NULL)) {
            tmp_mvar_value_154 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[179]);
        }

        if (tmp_mvar_value_154 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 80;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_155;
        tmp_mvar_value_155 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[180]);

        if (unlikely(tmp_mvar_value_155 == NULL)) {
            tmp_mvar_value_155 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[180]);
        }

        if (tmp_mvar_value_155 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_156;
        tmp_mvar_value_156 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[181]);

        if (unlikely(tmp_mvar_value_156 == NULL)) {
            tmp_mvar_value_156 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[181]);
        }

        if (tmp_mvar_value_156 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_157;
        tmp_mvar_value_157 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[182]);

        if (unlikely(tmp_mvar_value_157 == NULL)) {
            tmp_mvar_value_157 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[182]);
        }

        if (tmp_mvar_value_157 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_158;
        tmp_mvar_value_158 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[183]);

        if (unlikely(tmp_mvar_value_158 == NULL)) {
            tmp_mvar_value_158 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[183]);
        }

        if (tmp_mvar_value_158 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_159;
        tmp_mvar_value_159 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[184]);

        if (unlikely(tmp_mvar_value_159 == NULL)) {
            tmp_mvar_value_159 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[184]);
        }

        if (tmp_mvar_value_159 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_160;
        tmp_mvar_value_160 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[185]);

        if (unlikely(tmp_mvar_value_160 == NULL)) {
            tmp_mvar_value_160 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[185]);
        }

        if (tmp_mvar_value_160 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_161;
        tmp_mvar_value_161 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[186]);

        if (unlikely(tmp_mvar_value_161 == NULL)) {
            tmp_mvar_value_161 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[186]);
        }

        if (tmp_mvar_value_161 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_162;
        tmp_mvar_value_162 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[187]);

        if (unlikely(tmp_mvar_value_162 == NULL)) {
            tmp_mvar_value_162 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[187]);
        }

        if (tmp_mvar_value_162 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_163;
        tmp_mvar_value_163 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[188]);

        if (unlikely(tmp_mvar_value_163 == NULL)) {
            tmp_mvar_value_163 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[188]);
        }

        if (tmp_mvar_value_163 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_164;
        tmp_mvar_value_164 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[189]);

        if (unlikely(tmp_mvar_value_164 == NULL)) {
            tmp_mvar_value_164 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[189]);
        }

        if (tmp_mvar_value_164 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_165;
        tmp_mvar_value_165 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[190]);

        if (unlikely(tmp_mvar_value_165 == NULL)) {
            tmp_mvar_value_165 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[190]);
        }

        if (tmp_mvar_value_165 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_166;
        tmp_mvar_value_166 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[191]);

        if (unlikely(tmp_mvar_value_166 == NULL)) {
            tmp_mvar_value_166 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[191]);
        }

        if (tmp_mvar_value_166 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_167;
        tmp_mvar_value_167 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[192]);

        if (unlikely(tmp_mvar_value_167 == NULL)) {
            tmp_mvar_value_167 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[192]);
        }

        if (tmp_mvar_value_167 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_168;
        tmp_mvar_value_168 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[193]);

        if (unlikely(tmp_mvar_value_168 == NULL)) {
            tmp_mvar_value_168 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[193]);
        }

        if (tmp_mvar_value_168 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 81;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_169;
        tmp_mvar_value_169 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[194]);

        if (unlikely(tmp_mvar_value_169 == NULL)) {
            tmp_mvar_value_169 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[194]);
        }

        if (tmp_mvar_value_169 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_170;
        tmp_mvar_value_170 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[195]);

        if (unlikely(tmp_mvar_value_170 == NULL)) {
            tmp_mvar_value_170 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[195]);
        }

        if (tmp_mvar_value_170 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_171;
        tmp_mvar_value_171 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[196]);

        if (unlikely(tmp_mvar_value_171 == NULL)) {
            tmp_mvar_value_171 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[196]);
        }

        if (tmp_mvar_value_171 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_172;
        tmp_mvar_value_172 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[197]);

        if (unlikely(tmp_mvar_value_172 == NULL)) {
            tmp_mvar_value_172 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[197]);
        }

        if (tmp_mvar_value_172 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_173;
        tmp_mvar_value_173 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[198]);

        if (unlikely(tmp_mvar_value_173 == NULL)) {
            tmp_mvar_value_173 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[198]);
        }

        if (tmp_mvar_value_173 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_174;
        tmp_mvar_value_174 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[199]);

        if (unlikely(tmp_mvar_value_174 == NULL)) {
            tmp_mvar_value_174 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[199]);
        }

        if (tmp_mvar_value_174 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_175;
        tmp_mvar_value_175 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[200]);

        if (unlikely(tmp_mvar_value_175 == NULL)) {
            tmp_mvar_value_175 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[200]);
        }

        if (tmp_mvar_value_175 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_176;
        tmp_mvar_value_176 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[201]);

        if (unlikely(tmp_mvar_value_176 == NULL)) {
            tmp_mvar_value_176 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[201]);
        }

        if (tmp_mvar_value_176 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_177;
        tmp_mvar_value_177 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[202]);

        if (unlikely(tmp_mvar_value_177 == NULL)) {
            tmp_mvar_value_177 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[202]);
        }

        if (tmp_mvar_value_177 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_178;
        tmp_mvar_value_178 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[203]);

        if (unlikely(tmp_mvar_value_178 == NULL)) {
            tmp_mvar_value_178 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[203]);
        }

        if (tmp_mvar_value_178 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_179;
        tmp_mvar_value_179 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[204]);

        if (unlikely(tmp_mvar_value_179 == NULL)) {
            tmp_mvar_value_179 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[204]);
        }

        if (tmp_mvar_value_179 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_180;
        tmp_mvar_value_180 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[205]);

        if (unlikely(tmp_mvar_value_180 == NULL)) {
            tmp_mvar_value_180 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[205]);
        }

        if (tmp_mvar_value_180 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_181;
        tmp_mvar_value_181 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[206]);

        if (unlikely(tmp_mvar_value_181 == NULL)) {
            tmp_mvar_value_181 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[206]);
        }

        if (tmp_mvar_value_181 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_182;
        tmp_mvar_value_182 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[207]);

        if (unlikely(tmp_mvar_value_182 == NULL)) {
            tmp_mvar_value_182 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[207]);
        }

        if (tmp_mvar_value_182 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 82;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_183;
        tmp_mvar_value_183 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[208]);

        if (unlikely(tmp_mvar_value_183 == NULL)) {
            tmp_mvar_value_183 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[208]);
        }

        if (tmp_mvar_value_183 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_184;
        tmp_mvar_value_184 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[209]);

        if (unlikely(tmp_mvar_value_184 == NULL)) {
            tmp_mvar_value_184 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[209]);
        }

        if (tmp_mvar_value_184 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_185;
        tmp_mvar_value_185 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[210]);

        if (unlikely(tmp_mvar_value_185 == NULL)) {
            tmp_mvar_value_185 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[210]);
        }

        if (tmp_mvar_value_185 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_186;
        tmp_mvar_value_186 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[211]);

        if (unlikely(tmp_mvar_value_186 == NULL)) {
            tmp_mvar_value_186 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[211]);
        }

        if (tmp_mvar_value_186 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_187;
        tmp_mvar_value_187 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[212]);

        if (unlikely(tmp_mvar_value_187 == NULL)) {
            tmp_mvar_value_187 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[212]);
        }

        if (tmp_mvar_value_187 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_188;
        tmp_mvar_value_188 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[213]);

        if (unlikely(tmp_mvar_value_188 == NULL)) {
            tmp_mvar_value_188 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[213]);
        }

        if (tmp_mvar_value_188 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_189;
        tmp_mvar_value_189 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[214]);

        if (unlikely(tmp_mvar_value_189 == NULL)) {
            tmp_mvar_value_189 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[214]);
        }

        if (tmp_mvar_value_189 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_190;
        tmp_mvar_value_190 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[215]);

        if (unlikely(tmp_mvar_value_190 == NULL)) {
            tmp_mvar_value_190 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[215]);
        }

        if (tmp_mvar_value_190 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_191;
        tmp_mvar_value_191 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[216]);

        if (unlikely(tmp_mvar_value_191 == NULL)) {
            tmp_mvar_value_191 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[216]);
        }

        if (tmp_mvar_value_191 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_192;
        tmp_mvar_value_192 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[217]);

        if (unlikely(tmp_mvar_value_192 == NULL)) {
            tmp_mvar_value_192 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[217]);
        }

        if (tmp_mvar_value_192 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_193;
        tmp_mvar_value_193 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[218]);

        if (unlikely(tmp_mvar_value_193 == NULL)) {
            tmp_mvar_value_193 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[218]);
        }

        if (tmp_mvar_value_193 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_194;
        tmp_mvar_value_194 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[219]);

        if (unlikely(tmp_mvar_value_194 == NULL)) {
            tmp_mvar_value_194 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[219]);
        }

        if (tmp_mvar_value_194 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_195;
        tmp_mvar_value_195 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[220]);

        if (unlikely(tmp_mvar_value_195 == NULL)) {
            tmp_mvar_value_195 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[220]);
        }

        if (tmp_mvar_value_195 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_196;
        tmp_mvar_value_196 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[221]);

        if (unlikely(tmp_mvar_value_196 == NULL)) {
            tmp_mvar_value_196 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[221]);
        }

        if (tmp_mvar_value_196 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 83;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_197;
        tmp_mvar_value_197 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[222]);

        if (unlikely(tmp_mvar_value_197 == NULL)) {
            tmp_mvar_value_197 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[222]);
        }

        if (tmp_mvar_value_197 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_198;
        tmp_mvar_value_198 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[223]);

        if (unlikely(tmp_mvar_value_198 == NULL)) {
            tmp_mvar_value_198 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[223]);
        }

        if (tmp_mvar_value_198 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_199;
        tmp_mvar_value_199 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[224]);

        if (unlikely(tmp_mvar_value_199 == NULL)) {
            tmp_mvar_value_199 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[224]);
        }

        if (tmp_mvar_value_199 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_200;
        tmp_mvar_value_200 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[225]);

        if (unlikely(tmp_mvar_value_200 == NULL)) {
            tmp_mvar_value_200 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[225]);
        }

        if (tmp_mvar_value_200 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_201;
        tmp_mvar_value_201 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[226]);

        if (unlikely(tmp_mvar_value_201 == NULL)) {
            tmp_mvar_value_201 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[226]);
        }

        if (tmp_mvar_value_201 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_202;
        tmp_mvar_value_202 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[227]);

        if (unlikely(tmp_mvar_value_202 == NULL)) {
            tmp_mvar_value_202 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[227]);
        }

        if (tmp_mvar_value_202 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_203;
        tmp_mvar_value_203 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[228]);

        if (unlikely(tmp_mvar_value_203 == NULL)) {
            tmp_mvar_value_203 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[228]);
        }

        if (tmp_mvar_value_203 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_204;
        tmp_mvar_value_204 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[229]);

        if (unlikely(tmp_mvar_value_204 == NULL)) {
            tmp_mvar_value_204 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[229]);
        }

        if (tmp_mvar_value_204 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_205;
        tmp_mvar_value_205 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[230]);

        if (unlikely(tmp_mvar_value_205 == NULL)) {
            tmp_mvar_value_205 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[230]);
        }

        if (tmp_mvar_value_205 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_206;
        tmp_mvar_value_206 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[231]);

        if (unlikely(tmp_mvar_value_206 == NULL)) {
            tmp_mvar_value_206 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[231]);
        }

        if (tmp_mvar_value_206 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    {
        PyObject *tmp_mvar_value_207;
        tmp_mvar_value_207 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[232]);

        if (unlikely(tmp_mvar_value_207 == NULL)) {
            tmp_mvar_value_207 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[232]);
        }

        if (tmp_mvar_value_207 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 84;

            goto frame_exception_exit_1;
        }
    }
    // Tried code:
    {
        PyObject *tmp_assign_source_221;
        PyObject *tmp_dircall_arg1_1;
        tmp_dircall_arg1_1 = mod_consts[243];
        Py_INCREF(tmp_dircall_arg1_1);

        {
            PyObject *dir_call_args[] = {tmp_dircall_arg1_1};
            tmp_assign_source_221 = impl___main__$$$function__4__mro_entries_conversion(dir_call_args);
        }
        if (tmp_assign_source_221 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        assert(tmp_class_creation_1__bases == NULL);
        tmp_class_creation_1__bases = tmp_assign_source_221;
    }
    {
        PyObject *tmp_assign_source_222;
        tmp_assign_source_222 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_1__class_decl_dict == NULL);
        tmp_class_creation_1__class_decl_dict = tmp_assign_source_222;
    }
    {
        PyObject *tmp_assign_source_223;
        PyObject *tmp_metaclass_value_1;
        nuitka_bool tmp_condition_result_1;
        int tmp_truth_name_1;
        PyObject *tmp_type_arg_1;
        PyObject *tmp_expression_value_6;
        PyObject *tmp_subscript_value_2;
        PyObject *tmp_bases_value_1;
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_truth_name_1 = CHECK_IF_TRUE(tmp_class_creation_1__bases);
        if (tmp_truth_name_1 == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        tmp_condition_result_1 = tmp_truth_name_1 == 0 ? NUITKA_BOOL_FALSE : NUITKA_BOOL_TRUE;
        if (tmp_condition_result_1 == NUITKA_BOOL_TRUE) {
            goto condexpr_true_1;
        } else {
            goto condexpr_false_1;
        }
        condexpr_true_1:;
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_expression_value_6 = tmp_class_creation_1__bases;
        tmp_subscript_value_2 = mod_consts[12];
        tmp_type_arg_1 = LOOKUP_SUBSCRIPT_CONST(tmp_expression_value_6, tmp_subscript_value_2, 0);
        if (tmp_type_arg_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        tmp_metaclass_value_1 = BUILTIN_TYPE1(tmp_type_arg_1);
        Py_DECREF(tmp_type_arg_1);
        if (tmp_metaclass_value_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        goto condexpr_end_1;
        condexpr_false_1:;
        tmp_metaclass_value_1 = (PyObject *)&PyType_Type;
        Py_INCREF(tmp_metaclass_value_1);
        condexpr_end_1:;
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_bases_value_1 = tmp_class_creation_1__bases;
        tmp_assign_source_223 = SELECT_METACLASS(tmp_metaclass_value_1, tmp_bases_value_1);
        Py_DECREF(tmp_metaclass_value_1);
        if (tmp_assign_source_223 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        assert(tmp_class_creation_1__metaclass == NULL);
        tmp_class_creation_1__metaclass = tmp_assign_source_223;
    }
    {
        nuitka_bool tmp_condition_result_2;
        PyObject *tmp_expression_value_7;
        CHECK_OBJECT(tmp_class_creation_1__metaclass);
        tmp_expression_value_7 = tmp_class_creation_1__metaclass;
        tmp_result = HAS_ATTR_BOOL(tmp_expression_value_7, mod_consts[244]);
        tmp_condition_result_2 = (tmp_result) ? NUITKA_BOOL_TRUE : NUITKA_BOOL_FALSE;
        if (tmp_condition_result_2 == NUITKA_BOOL_TRUE) {
            goto branch_yes_1;
        } else {
            goto branch_no_1;
        }
    }
    branch_yes_1:;
    {
        PyObject *tmp_assign_source_224;
        PyObject *tmp_called_value_5;
        PyObject *tmp_expression_value_8;
        PyObject *tmp_args_value_1;
        PyObject *tmp_tuple_element_1;
        PyObject *tmp_kwargs_value_1;
        CHECK_OBJECT(tmp_class_creation_1__metaclass);
        tmp_expression_value_8 = tmp_class_creation_1__metaclass;
        tmp_called_value_5 = LOOKUP_ATTRIBUTE(tmp_expression_value_8, mod_consts[244]);
        if (tmp_called_value_5 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        tmp_tuple_element_1 = mod_consts[245];
        tmp_args_value_1 = MAKE_TUPLE_EMPTY(2);
        PyTuple_SET_ITEM0(tmp_args_value_1, 0, tmp_tuple_element_1);
        CHECK_OBJECT(tmp_class_creation_1__bases);
        tmp_tuple_element_1 = tmp_class_creation_1__bases;
        PyTuple_SET_ITEM0(tmp_args_value_1, 1, tmp_tuple_element_1);
        CHECK_OBJECT(tmp_class_creation_1__class_decl_dict);
        tmp_kwargs_value_1 = tmp_class_creation_1__class_decl_dict;
        frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 88;
        tmp_assign_source_224 = CALL_FUNCTION(tmp_called_value_5, tmp_args_value_1, tmp_kwargs_value_1);
        Py_DECREF(tmp_called_value_5);
        Py_DECREF(tmp_args_value_1);
        if (tmp_assign_source_224 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        assert(tmp_class_creation_1__prepared == NULL);
        tmp_class_creation_1__prepared = tmp_assign_source_224;
    }
    {
        bool tmp_condition_result_3;
        PyObject *tmp_operand_value_1;
        PyObject *tmp_expression_value_9;
        CHECK_OBJECT(tmp_class_creation_1__prepared);
        tmp_expression_value_9 = tmp_class_creation_1__prepared;
        tmp_result = HAS_ATTR_BOOL(tmp_expression_value_9, mod_consts[246]);
        tmp_operand_value_1 = (tmp_result) ? Py_True : Py_False;
        tmp_res = CHECK_IF_TRUE(tmp_operand_value_1);
        if (tmp_res == -1) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        tmp_condition_result_3 = (tmp_res == 0) ? true : false;
        if (tmp_condition_result_3 != false) {
            goto branch_yes_2;
        } else {
            goto branch_no_2;
        }
    }
    branch_yes_2:;
    {
        PyObject *tmp_raise_type_1;
        PyObject *tmp_raise_value_1;
        PyObject *tmp_mod_expr_left_1;
        PyObject *tmp_mod_expr_right_1;
        PyObject *tmp_tuple_element_2;
        PyObject *tmp_getattr_target_1;
        PyObject *tmp_getattr_attr_1;
        PyObject *tmp_getattr_default_1;
        tmp_raise_type_1 = PyExc_TypeError;
        tmp_mod_expr_left_1 = mod_consts[247];
        CHECK_OBJECT(tmp_class_creation_1__metaclass);
        tmp_getattr_target_1 = tmp_class_creation_1__metaclass;
        tmp_getattr_attr_1 = mod_consts[248];
        tmp_getattr_default_1 = mod_consts[249];
        tmp_tuple_element_2 = BUILTIN_GETATTR(tmp_getattr_target_1, tmp_getattr_attr_1, tmp_getattr_default_1);
        if (tmp_tuple_element_2 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        tmp_mod_expr_right_1 = MAKE_TUPLE_EMPTY(2);
        {
            PyObject *tmp_expression_value_10;
            PyObject *tmp_type_arg_2;
            PyTuple_SET_ITEM(tmp_mod_expr_right_1, 0, tmp_tuple_element_2);
            CHECK_OBJECT(tmp_class_creation_1__prepared);
            tmp_type_arg_2 = tmp_class_creation_1__prepared;
            tmp_expression_value_10 = BUILTIN_TYPE1(tmp_type_arg_2);
            assert(!(tmp_expression_value_10 == NULL));
            tmp_tuple_element_2 = LOOKUP_ATTRIBUTE(tmp_expression_value_10, mod_consts[248]);
            Py_DECREF(tmp_expression_value_10);
            if (tmp_tuple_element_2 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 88;

                goto tuple_build_exception_1;
            }
            PyTuple_SET_ITEM(tmp_mod_expr_right_1, 1, tmp_tuple_element_2);
        }
        goto tuple_build_noexception_1;
        // Exception handling pass through code for tuple_build:
        tuple_build_exception_1:;
        Py_DECREF(tmp_mod_expr_right_1);
        goto try_except_handler_8;
        // Finished with no exception for tuple_build:
        tuple_build_noexception_1:;
        tmp_raise_value_1 = BINARY_OPERATION_MOD_OBJECT_UNICODE_TUPLE(tmp_mod_expr_left_1, tmp_mod_expr_right_1);
        Py_DECREF(tmp_mod_expr_right_1);
        if (tmp_raise_value_1 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_8;
        }
        exception_type = tmp_raise_type_1;
        Py_INCREF(tmp_raise_type_1);
        exception_value = tmp_raise_value_1;
        exception_lineno = 88;
        RAISE_EXCEPTION_IMPLICIT(&exception_type, &exception_value, &exception_tb);

        goto try_except_handler_8;
    }
    branch_no_2:;
    goto branch_end_1;
    branch_no_1:;
    {
        PyObject *tmp_assign_source_225;
        tmp_assign_source_225 = MAKE_DICT_EMPTY();
        assert(tmp_class_creation_1__prepared == NULL);
        tmp_class_creation_1__prepared = tmp_assign_source_225;
    }
    branch_end_1:;
    {
        PyObject *tmp_assign_source_226;
        {
            PyObject *tmp_set_locals_1;
            CHECK_OBJECT(tmp_class_creation_1__prepared);
            tmp_set_locals_1 = tmp_class_creation_1__prepared;
            locals_mutagen$id3$$$class__1__DummySpecForPicard_88 = tmp_set_locals_1;
            Py_INCREF(tmp_set_locals_1);
        }
        // Tried code:
        // Tried code:
        tmp_dictset_value = mod_consts[250];
        tmp_res = PyObject_SetItem(locals_mutagen$id3$$$class__1__DummySpecForPicard_88, mod_consts[251], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_10;
        }
        tmp_dictset_value = mod_consts[245];
        tmp_res = PyObject_SetItem(locals_mutagen$id3$$$class__1__DummySpecForPicard_88, mod_consts[252], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_10;
        }
        frame_40a23018839a78e0169f1236ebf59485_2 = MAKE_CLASS_FRAME(codeobj_40a23018839a78e0169f1236ebf59485, module_mutagen$id3, NULL, sizeof(void *));

        // Push the new frame as the currently active one, and we should be exclusively
        // owning it.
        pushFrameStackCompiledFrame(frame_40a23018839a78e0169f1236ebf59485_2);
        assert(Py_REFCNT(frame_40a23018839a78e0169f1236ebf59485_2) == 2);

        // Framed code:
        tmp_dictset_value = Py_None;
        tmp_res = PyObject_SetItem(locals_mutagen$id3$$$class__1__DummySpecForPicard_88, mod_consts[253], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 89;
            type_description_2 = "o";
            goto frame_exception_exit_2;
        }


        // Put the previous frame back on top.
        popFrameStack();

        goto frame_no_exception_1;
        frame_exception_exit_2:


        if (exception_tb == NULL) {
            exception_tb = MAKE_TRACEBACK(frame_40a23018839a78e0169f1236ebf59485_2, exception_lineno);
        } else if (exception_tb->tb_frame != &frame_40a23018839a78e0169f1236ebf59485_2->m_frame) {
            exception_tb = ADD_TRACEBACK(exception_tb, frame_40a23018839a78e0169f1236ebf59485_2, exception_lineno);
        }

        // Attaches locals to frame if any.
        Nuitka_Frame_AttachLocals(
            frame_40a23018839a78e0169f1236ebf59485_2,
            type_description_2,
            outline_0_var___class__
        );



        assertFrameObject(frame_40a23018839a78e0169f1236ebf59485_2);

        // Put the previous frame back on top.
        popFrameStack();

        // Return the error.
        goto nested_frame_exit_1;
        frame_no_exception_1:;
        goto skip_nested_handling_1;
        nested_frame_exit_1:;

        goto try_except_handler_10;
        skip_nested_handling_1:;
        {
            nuitka_bool tmp_condition_result_4;
            PyObject *tmp_cmp_expr_left_1;
            PyObject *tmp_cmp_expr_right_1;
            CHECK_OBJECT(tmp_class_creation_1__bases);
            tmp_cmp_expr_left_1 = tmp_class_creation_1__bases;
            tmp_cmp_expr_right_1 = mod_consts[243];
            tmp_condition_result_4 = RICH_COMPARE_NE_NBOOL_OBJECT_TUPLE(tmp_cmp_expr_left_1, tmp_cmp_expr_right_1);
            if (tmp_condition_result_4 == NUITKA_BOOL_EXCEPTION) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 88;

                goto try_except_handler_10;
            }
            if (tmp_condition_result_4 == NUITKA_BOOL_TRUE) {
                goto branch_yes_3;
            } else {
                goto branch_no_3;
            }
        }
        branch_yes_3:;
        tmp_dictset_value = mod_consts[243];
        tmp_res = PyObject_SetItem(locals_mutagen$id3$$$class__1__DummySpecForPicard_88, mod_consts[254], tmp_dictset_value);
        if (tmp_res != 0) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 88;

            goto try_except_handler_10;
        }
        branch_no_3:;
        {
            PyObject *tmp_assign_source_227;
            PyObject *tmp_called_value_6;
            PyObject *tmp_args_value_2;
            PyObject *tmp_tuple_element_3;
            PyObject *tmp_kwargs_value_2;
            CHECK_OBJECT(tmp_class_creation_1__metaclass);
            tmp_called_value_6 = tmp_class_creation_1__metaclass;
            tmp_tuple_element_3 = mod_consts[245];
            tmp_args_value_2 = MAKE_TUPLE_EMPTY(3);
            PyTuple_SET_ITEM0(tmp_args_value_2, 0, tmp_tuple_element_3);
            CHECK_OBJECT(tmp_class_creation_1__bases);
            tmp_tuple_element_3 = tmp_class_creation_1__bases;
            PyTuple_SET_ITEM0(tmp_args_value_2, 1, tmp_tuple_element_3);
            tmp_tuple_element_3 = locals_mutagen$id3$$$class__1__DummySpecForPicard_88;
            PyTuple_SET_ITEM0(tmp_args_value_2, 2, tmp_tuple_element_3);
            CHECK_OBJECT(tmp_class_creation_1__class_decl_dict);
            tmp_kwargs_value_2 = tmp_class_creation_1__class_decl_dict;
            frame_84e2103a5ab58db66ba53134f0d612b3->m_frame.f_lineno = 88;
            tmp_assign_source_227 = CALL_FUNCTION(tmp_called_value_6, tmp_args_value_2, tmp_kwargs_value_2);
            Py_DECREF(tmp_args_value_2);
            if (tmp_assign_source_227 == NULL) {
                assert(ERROR_OCCURRED());

                FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


                exception_lineno = 88;

                goto try_except_handler_10;
            }
            assert(outline_0_var___class__ == NULL);
            outline_0_var___class__ = tmp_assign_source_227;
        }
        CHECK_OBJECT(outline_0_var___class__);
        tmp_assign_source_226 = outline_0_var___class__;
        Py_INCREF(tmp_assign_source_226);
        goto try_return_handler_10;
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_10:;
        Py_DECREF(locals_mutagen$id3$$$class__1__DummySpecForPicard_88);
        locals_mutagen$id3$$$class__1__DummySpecForPicard_88 = NULL;
        goto try_return_handler_9;
        // Exception handler code:
        try_except_handler_10:;
        exception_keeper_type_8 = exception_type;
        exception_keeper_value_8 = exception_value;
        exception_keeper_tb_8 = exception_tb;
        exception_keeper_lineno_8 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        Py_DECREF(locals_mutagen$id3$$$class__1__DummySpecForPicard_88);
        locals_mutagen$id3$$$class__1__DummySpecForPicard_88 = NULL;
        // Re-raise.
        exception_type = exception_keeper_type_8;
        exception_value = exception_keeper_value_8;
        exception_tb = exception_keeper_tb_8;
        exception_lineno = exception_keeper_lineno_8;

        goto try_except_handler_9;
        // End of try:
        NUITKA_CANNOT_GET_HERE("tried codes exits in all cases");
        return NULL;
        // Return handler code:
        try_return_handler_9:;
        CHECK_OBJECT(outline_0_var___class__);
        Py_DECREF(outline_0_var___class__);
        outline_0_var___class__ = NULL;
        goto outline_result_1;
        // Exception handler code:
        try_except_handler_9:;
        exception_keeper_type_9 = exception_type;
        exception_keeper_value_9 = exception_value;
        exception_keeper_tb_9 = exception_tb;
        exception_keeper_lineno_9 = exception_lineno;
        exception_type = NULL;
        exception_value = NULL;
        exception_tb = NULL;
        exception_lineno = 0;

        // Re-raise.
        exception_type = exception_keeper_type_9;
        exception_value = exception_keeper_value_9;
        exception_tb = exception_keeper_tb_9;
        exception_lineno = exception_keeper_lineno_9;

        goto outline_exception_1;
        // End of try:
        NUITKA_CANNOT_GET_HERE("Return statement must have exited already.");
        return NULL;
        outline_exception_1:;
        exception_lineno = 88;
        goto try_except_handler_8;
        outline_result_1:;
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[245], tmp_assign_source_226);
    }
    goto try_end_8;
    // Exception handler code:
    try_except_handler_8:;
    exception_keeper_type_10 = exception_type;
    exception_keeper_value_10 = exception_value;
    exception_keeper_tb_10 = exception_tb;
    exception_keeper_lineno_10 = exception_lineno;
    exception_type = NULL;
    exception_value = NULL;
    exception_tb = NULL;
    exception_lineno = 0;

    Py_XDECREF(tmp_class_creation_1__bases);
    tmp_class_creation_1__bases = NULL;
    Py_XDECREF(tmp_class_creation_1__class_decl_dict);
    tmp_class_creation_1__class_decl_dict = NULL;
    Py_XDECREF(tmp_class_creation_1__metaclass);
    tmp_class_creation_1__metaclass = NULL;
    Py_XDECREF(tmp_class_creation_1__prepared);
    tmp_class_creation_1__prepared = NULL;
    // Re-raise.
    exception_type = exception_keeper_type_10;
    exception_value = exception_keeper_value_10;
    exception_tb = exception_keeper_tb_10;
    exception_lineno = exception_keeper_lineno_10;

    goto frame_exception_exit_1;
    // End of try:
    try_end_8:;
    CHECK_OBJECT(tmp_class_creation_1__bases);
    Py_DECREF(tmp_class_creation_1__bases);
    tmp_class_creation_1__bases = NULL;
    CHECK_OBJECT(tmp_class_creation_1__class_decl_dict);
    Py_DECREF(tmp_class_creation_1__class_decl_dict);
    tmp_class_creation_1__class_decl_dict = NULL;
    CHECK_OBJECT(tmp_class_creation_1__metaclass);
    Py_DECREF(tmp_class_creation_1__metaclass);
    tmp_class_creation_1__metaclass = NULL;
    CHECK_OBJECT(tmp_class_creation_1__prepared);
    Py_DECREF(tmp_class_creation_1__prepared);
    tmp_class_creation_1__prepared = NULL;
    {
        PyObject *tmp_assign_source_228;
        tmp_assign_source_228 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[245]);

        if (unlikely(tmp_assign_source_228 == NULL)) {
            tmp_assign_source_228 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[245]);
        }

        if (tmp_assign_source_228 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 91;

            goto frame_exception_exit_1;
        }
        assert(tmp_assign_unpack_1__assign_source == NULL);
        Py_INCREF(tmp_assign_source_228);
        tmp_assign_unpack_1__assign_source = tmp_assign_source_228;
    }
    {
        PyObject *tmp_assign_source_229;
        CHECK_OBJECT(tmp_assign_unpack_1__assign_source);
        tmp_assign_source_229 = tmp_assign_unpack_1__assign_source;
        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[255], tmp_assign_source_229);
    }
    {
        PyObject *tmp_assign_source_230;
        CHECK_OBJECT(tmp_assign_unpack_1__assign_source);
        tmp_assign_source_230 = tmp_assign_unpack_1__assign_source;
        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[256], tmp_assign_source_230);
    }
    CHECK_OBJECT(tmp_assign_unpack_1__assign_source);
    Py_DECREF(tmp_assign_unpack_1__assign_source);
    tmp_assign_unpack_1__assign_source = NULL;
    {
        PyObject *tmp_assign_source_231;
        tmp_assign_source_231 = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[241]);

        if (unlikely(tmp_assign_source_231 == NULL)) {
            tmp_assign_source_231 = GET_MODULE_VARIABLE_VALUE_FALLBACK(mod_consts[241]);
        }

        if (tmp_assign_source_231 == NULL) {
            assert(ERROR_OCCURRED());

            FETCH_ERROR_OCCURRED(&exception_type, &exception_value, &exception_tb);


            exception_lineno = 92;

            goto frame_exception_exit_1;
        }
        UPDATE_STRING_DICT0(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[240], tmp_assign_source_231);
    }


    // Put the previous frame back on top.
    popFrameStack();

    goto frame_no_exception_2;
    frame_exception_exit_1:


    if (exception_tb == NULL) {
        exception_tb = MAKE_TRACEBACK(frame_84e2103a5ab58db66ba53134f0d612b3, exception_lineno);
    } else if (exception_tb->tb_frame != &frame_84e2103a5ab58db66ba53134f0d612b3->m_frame) {
        exception_tb = ADD_TRACEBACK(exception_tb, frame_84e2103a5ab58db66ba53134f0d612b3, exception_lineno);
    }



    assertFrameObject(frame_84e2103a5ab58db66ba53134f0d612b3);

    // Put the previous frame back on top.
    popFrameStack();

    // Return the error.
    goto module_exception_exit;
    frame_no_exception_2:;
    {
        PyObject *tmp_assign_source_232;
        tmp_assign_source_232 = MAKE_LIST5(mod_consts[257]);
        UPDATE_STRING_DICT1(moduledict_mutagen$id3, (Nuitka_StringObject *)mod_consts[258], tmp_assign_source_232);
    }

    // Report to PGO about leaving the module without error.
    PGO_onModuleExit("mutagen.id3", false);

    Py_INCREF(module_mutagen$id3);
    return module_mutagen$id3;
    module_exception_exit:

#if defined(_NUITKA_MODULE) && 0
    {
        PyObject *module_name = GET_STRING_DICT_VALUE(moduledict_mutagen$id3, (Nuitka_StringObject *)const_str_plain___name__);

        if (module_name != NULL) {
            Nuitka_DelModule(module_name);
        }
    }
#endif
    PGO_onModuleExit("mutagen$id3", false);

    RESTORE_ERROR_OCCURRED(exception_type, exception_value, exception_tb);
    return NULL;
}
