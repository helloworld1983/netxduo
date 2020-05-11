/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Component                                                        */
/**                                                                       */
/**   Trace                                                               */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#ifndef NX_SOURCE_CODE
#define NX_SOURCE_CODE
#endif

/* Include necessary system files.  */

#include "nx_api.h"


#ifdef TX_ENABLE_EVENT_TRACE
extern VOID _tx_trace_object_register(UCHAR, VOID *, CHAR *, ULONG, ULONG);
/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_trace_object_register                           PORTABLE C      */
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function registers a NetX Duo object in the trace registry.    */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    object_type                           Type of system object         */
/*    object_ptr                            Address of system object      */
/*    object_name                           Name of system object         */
/*    parameter_1                           Supplemental parameter 1      */
/*    parameter_2                           Supplemental parameter 2      */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _tx_trace_object_register             Actual register function      */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Initialization                                          */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Yuxin Zhou               Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/
VOID  _nx_trace_object_register(UCHAR object_type, VOID *object_ptr, CHAR *object_name, ULONG parameter_1, ULONG parameter_2)
{

TX_INTERRUPT_SAVE_AREA


    /* Disable interrupts.  */
    TX_DISABLE

    /* Call actual object register function.  */
    _tx_trace_object_register(object_type, object_ptr, object_name, parameter_1, parameter_2);

    /* Restore interrupts.  */
    TX_RESTORE
}
#endif
