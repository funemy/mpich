/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include "mpitestconf.h"
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#include "mpitest.h"

static int verbose = 0;

/* tests */
int contig_test(void);

/* helper functions */
int parse_args(int argc, char **argv);

int main(int argc, char **argv)
{
    int err, errs = 0;

    MTest_Init(&argc, &argv);
    parse_args(argc, argv);

    /* To improve reporting of problems about operations, we
     * change the error handler to errors return */
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

    /* perform some tests */
    err = contig_test();
    if (err && verbose)
        fprintf(stderr, "%d errors in contig test.\n", err);
    errs += err;

    MTest_Finalize(errs);
    return MTestReturnValue(errs);
}

/* contig_test()
 *
 * Tests behavior with a zero-count contig.
 *
 * Returns the number of errors encountered.
 */
int contig_test(void)
{
    int err, errs = 0;

    int count = 0;
    MPI_Datatype newtype;

    int size;
    MPI_Aint extent, tmp_lb;

    err = MPI_Type_contiguous(count, MPI_INT, &newtype);
    if (err != MPI_SUCCESS) {
        if (verbose) {
            fprintf(stderr, "error creating type in contig_test()\n");
        }
        errs++;
    }

    err = MPI_Type_size(newtype, &size);
    if (err != MPI_SUCCESS) {
        if (verbose) {
            fprintf(stderr, "error obtaining type size in contig_test()\n");
        }
        errs++;
    }

    if (size != 0) {
        if (verbose) {
            fprintf(stderr, "error: size != 0 in contig_test()\n");
        }
        errs++;
    }

    err = MPI_Type_get_extent(newtype, &tmp_lb, &extent);
    if (err != MPI_SUCCESS) {
        if (verbose) {
            fprintf(stderr, "error obtaining type extent in contig_test()\n");
        }
        errs++;
    }

    if (extent != 0) {
        if (verbose) {
            fprintf(stderr, "error: extent != 0 in contig_test()\n");
        }
        errs++;
    }

    MPI_Type_free(&newtype);

    return errs;
}


int parse_args(int argc, char **argv)
{
    /*
     * int ret;
     *
     * while ((ret = getopt(argc, argv, "v")) >= 0)
     * {
     * switch (ret) {
     * case 'v':
     * verbose = 1;
     * break;
     * }
     * }
     */
    if (argc > 1 && strcmp(argv[1], "-v") == 0)
        verbose = 1;
    return 0;
}
