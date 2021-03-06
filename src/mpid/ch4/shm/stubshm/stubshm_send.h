/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#ifndef STUBSHM_SEND_H_INCLUDED
#define STUBSHM_SEND_H_INCLUDED

#include "stubshm_impl.h"

MPL_STATIC_INLINE_PREFIX int MPIDI_STUBSHM_irsend(const void *buf,
                                                  MPI_Aint count,
                                                  MPI_Datatype datatype,
                                                  int rank,
                                                  int tag,
                                                  MPIR_Comm * comm, int context_offset,
                                                  MPIR_Request ** request)
{
    MPIR_FUNC_VERBOSE_STATE_DECL(MPID_STATE_MPIDI_STUBSHM_IRSEND);
    MPIR_FUNC_VERBOSE_ENTER(MPID_STATE_MPIDI_STUBSHM_IRSEND);

    MPIR_Assert(0);

    MPIR_FUNC_VERBOSE_EXIT(MPID_STATE_MPIDI_STUBSHM_IRSEND);
    return MPI_SUCCESS;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_STUBSHM_mpi_isend(const void *buf,
                                                     MPI_Aint count,
                                                     MPI_Datatype datatype,
                                                     int rank,
                                                     int tag,
                                                     MPIR_Comm * comm, int context_offset,
                                                     MPIR_Request ** request)
{
    MPIR_FUNC_VERBOSE_STATE_DECL(MPID_STATE_MPIDI_STUBSHM_MPI_ISEND);
    MPIR_FUNC_VERBOSE_ENTER(MPID_STATE_MPIDI_STUBSHM_MPI_ISEND);

    MPIR_Assert(0);

    MPIR_FUNC_VERBOSE_EXIT(MPID_STATE_MPIDI_STUBSHM_MPI_ISEND);
    return MPI_SUCCESS;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_STUBSHM_mpi_issend(const void *buf,
                                                      MPI_Aint count,
                                                      MPI_Datatype datatype,
                                                      int rank,
                                                      int tag,
                                                      MPIR_Comm * comm, int context_offset,
                                                      MPIR_Request ** request)
{
    MPIR_FUNC_VERBOSE_STATE_DECL(MPID_STATE_MPIDI_STUBSHM_MPI_ISSEND);
    MPIR_FUNC_VERBOSE_ENTER(MPID_STATE_MPIDI_STUBSHM_MPI_ISSEND);

    MPIR_Assert(0);

    MPIR_FUNC_VERBOSE_EXIT(MPID_STATE_MPIDI_STUBSHM_MPI_ISSEND);
    return MPI_SUCCESS;
}

MPL_STATIC_INLINE_PREFIX int MPIDI_STUBSHM_mpi_cancel_send(MPIR_Request * sreq)
{
    MPIR_FUNC_VERBOSE_STATE_DECL(MPID_STATE_MPIDI_STUBSHM_MPI_CANCEL_SEND);
    MPIR_FUNC_VERBOSE_ENTER(MPID_STATE_MPIDI_STUBSHM_MPI_CANCEL_SEND);

    MPIR_Assert(0);

    MPIR_FUNC_VERBOSE_EXIT(MPID_STATE_MPIDI_STUBSHM_MPI_CANCEL_SEND);
    return MPI_SUCCESS;
}

#endif /* STUBSHM_SEND_H_INCLUDED */
