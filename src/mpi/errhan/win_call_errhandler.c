/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpiimpl.h"

/* -- Begin Profiling Symbol Block for routine MPI_Win_call_errhandler */
#if defined(HAVE_PRAGMA_WEAK)
#pragma weak MPI_Win_call_errhandler = PMPI_Win_call_errhandler
#elif defined(HAVE_PRAGMA_HP_SEC_DEF)
#pragma _HP_SECONDARY_DEF PMPI_Win_call_errhandler  MPI_Win_call_errhandler
#elif defined(HAVE_PRAGMA_CRI_DUP)
#pragma _CRI duplicate MPI_Win_call_errhandler as PMPI_Win_call_errhandler
#elif defined(HAVE_WEAK_ATTRIBUTE)
int MPI_Win_call_errhandler(MPI_Win win, int errorcode)
    __attribute__ ((weak, alias("PMPI_Win_call_errhandler")));
#endif
/* -- End Profiling Symbol Block */

/* Define MPICH_MPI_FROM_PMPI if weak symbols are not supported to build
   the MPI routines */
#ifndef MPICH_MPI_FROM_PMPI
#undef MPI_Win_call_errhandler
#define MPI_Win_call_errhandler PMPI_Win_call_errhandler

#endif


/*@
   MPI_Win_call_errhandler - Call the error handler installed on a
   window object

Input Parameters:
+ win - window with error handler (handle)
- errorcode - error code (integer)

 Note:
 Assuming the input parameters are valid, when the error handler is set to
 MPI_ERRORS_RETURN, this routine will always return MPI_SUCCESS.

.N ThreadSafeNoUpdate

.N Fortran

.N Errors
.N MPI_SUCCESS
.N MPI_ERR_WIN
@*/
int MPI_Win_call_errhandler(MPI_Win win, int errorcode)
{
    int mpi_errno = MPI_SUCCESS;
    MPIR_Win *win_ptr = NULL;
    MPIR_FUNC_TERSE_STATE_DECL(MPID_STATE_MPI_WIN_CALL_ERRHANDLER);

    MPIR_ERRTEST_INITIALIZED_ORDIE();

    MPIR_FUNC_TERSE_ENTER(MPID_STATE_MPI_WIN_CALL_ERRHANDLER);

    /* Validate parameters, especially handles needing to be converted */
#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            MPIR_ERRTEST_WIN(win, mpi_errno);
        }
        MPID_END_ERROR_CHECKS;
    }
#endif

    /* Convert MPI object handles to object pointers */
    MPIR_Win_get_ptr(win, win_ptr);

    /* Validate parameters and objects (post conversion) */
#ifdef HAVE_ERROR_CHECKING
    {
        MPID_BEGIN_ERROR_CHECKS;
        {
            /* Validate win_ptr */
            MPIR_Win_valid_ptr(win_ptr, mpi_errno);
            /* If win_ptr is not valid, it will be reset to null */
            if (mpi_errno)
                goto fn_fail;
        }
        MPID_END_ERROR_CHECKS;
    }
#endif /* HAVE_ERROR_CHECKING */

    /* ... body of routine ...  */

    mpi_errno = MPIR_Win_call_errhandler_impl(win_ptr, errorcode);

    /* ... end of body of routine ... */

  fn_exit:
    MPIR_FUNC_TERSE_EXIT(MPID_STATE_MPI_WIN_CALL_ERRHANDLER);
    return mpi_errno;

    /* --BEGIN ERROR HANDLING-- */
#ifdef HAVE_ERROR_CHECKING
  fn_fail:
    {
        mpi_errno =
            MPIR_Err_create_code(mpi_errno, MPIR_ERR_RECOVERABLE, __func__, __LINE__, MPI_ERR_OTHER,
                                 "**mpi_win_call_errhandler", "**mpi_win_call_errhandler %W %d",
                                 win, errorcode);
    }
    mpi_errno = MPIR_Err_return_win(win_ptr, __func__, mpi_errno);
    goto fn_exit;
#endif
    /* --END ERROR HANDLING-- */
}
