// -*- C++ -*-

//==============================================================================
/**
 *  @file        arg_types.h
 *
 *  $Id: Arg_Traits.h 2305 2013-10-07 03:23:23Z hillj $
 *
 *  @author      Dennis Feiock
 */
//==============================================================================

#ifndef _OASIS_PIN_ARG_H_
#define _OASIS_PIN_ARG_H_

#include "pin.H"

namespace OASIS
{
namespace Pin
{

class Context;
class Const_Context;

/**
 * @struct Arg_T
 *
 * Struct for converting PIN IARG_TYPEs to their parameter types
 */
template <IARG_TYPE T, typename PARAM_TYPE>
struct Arg_T
{
  static const IARG_TYPE arg_type = T;
  typedef PARAM_TYPE param_type;
};

#define DEFINE_ARG_TYPE(TYPENAME, IARG, PARAM_TYPE) \
  typedef Arg_T <IARG, PARAM_TYPE> TYPENAME

DEFINE_ARG_TYPE (ARG_INST_PTR, ::IARG_INST_PTR, ADDRINT);
DEFINE_ARG_TYPE (ARG_THREAD_ID, ::IARG_THREAD_ID, THREADID);

DEFINE_ARG_TYPE (ARG_REG_VALUE, ::IARG_REG_VALUE, ADDRINT);
DEFINE_ARG_TYPE (ARG_REG_REFERENCE, ::IARG_REG_REFERENCE, PIN_REGISTER *);
DEFINE_ARG_TYPE (ARG_REG_CONST_REFERENCE, ::IARG_REG_CONST_REFERENCE, PIN_REGISTER *);

DEFINE_ARG_TYPE (ARG_MEMORYREAD_EA, ::IARG_MEMORYREAD_EA, ADDRINT);
DEFINE_ARG_TYPE (ARG_MEMORYREAD2_EA, ::IARG_MEMORYREAD2_EA, ADDRINT);
DEFINE_ARG_TYPE (ARG_MEMORYWRITE_EA, ::IARG_MEMORYWRITE_EA, ADDRINT);
DEFINE_ARG_TYPE (ARG_MEMORYREAD_SIZE, ::IARG_MEMORYREAD_SIZE, UINT32);
DEFINE_ARG_TYPE (ARG_MEMORYWRITE_SIZE, ::IARG_MEMORYWRITE_SIZE, UINT32);
DEFINE_ARG_TYPE (ARG_MULTI_MEMORYACCESS_EA, ::IARG_MULTI_MEMORYACCESS_EA, PIN_MULTI_MEM_ACCESS_INFO *);

DEFINE_ARG_TYPE (ARG_BRANCH_TAKEN, ::IARG_BRANCH_TAKEN, BOOL);
DEFINE_ARG_TYPE (ARG_BRANCH_TARGET_ADDR, ::IARG_BRANCH_TARGET_ADDR, ADDRINT);
DEFINE_ARG_TYPE (ARG_FALLTHROUGH_ADDR, ::IARG_FALLTHROUGH_ADDR, ADDRINT);

DEFINE_ARG_TYPE (ARG_EXECUTING, ::IARG_EXECUTING, BOOL);
DEFINE_ARG_TYPE (ARG_FIRST_REP_ITERATION, ::IARG_FIRST_REP_ITERATION, BOOL);

DEFINE_ARG_TYPE (ARG_CONTEXT, ::IARG_CONTEXT, OASIS::Pin::Context);
DEFINE_ARG_TYPE (ARG_CONST_CONTEXT, ::IARG_CONST_CONTEXT, CONTEXT *);

DEFINE_ARG_TYPE (ARG_MEMORYOP_EA, ::IARG_MEMORYOP_EA, ADDRINT);
DEFINE_ARG_TYPE (ARG_MEMORYOP_MASKED_ON, ::IARG_MEMORYOP_MASKED_ON, BOOL);
DEFINE_ARG_TYPE (ARG_TSC, ::IARG_TSC, UINT64);

// Function arguments
DEFINE_ARG_TYPE (ARG_FUNCARG_CALLSITE_REFERENCE, ::IARG_FUNCARG_CALLSITE_REFERENCE, ADDRINT *);
DEFINE_ARG_TYPE (ARG_FUNCARG_CALLSITE_VALUE, ::IARG_FUNCARG_CALLSITE_VALUE, ADDRINT);
DEFINE_ARG_TYPE (ARG_FUNCARG_ENTRYPOINT_VALUE, ::IARG_FUNCARG_ENTRYPOINT_VALUE, ADDRINT);
DEFINE_ARG_TYPE (ARG_FUNCARG_ENTRYPOINT_REFERENCE, ::IARG_FUNCARG_ENTRYPOINT_REFERENCE, ADDRINT *);
DEFINE_ARG_TYPE (ARG_FUNCRET_EXITPOINT_VALUE, ::IARG_FUNCRET_EXITPOINT_VALUE, ADDRINT);
DEFINE_ARG_TYPE (ARG_FUNCRET_EXITPOINT_REFERENCE, ::IARG_FUNCRET_EXITPOINT_REFERENCE, ADDRINT *);

// Syscall stuff
DEFINE_ARG_TYPE (ARG_SYSCALL_NUMBER, ::IARG_SYSCALL_NUMBER, ADDRINT);
DEFINE_ARG_TYPE (ARG_SYSARG_REFERENCE, ::IARG_SYSARG_REFERENCE, ADDRINT *);
DEFINE_ARG_TYPE (ARG_SYSARG_VALUE, ::IARG_SYSARG_VALUE, ADDRINT);
DEFINE_ARG_TYPE (ARG_SYSRET_VALUE, ::IARG_SYSRET_VALUE, ADDRINT);
DEFINE_ARG_TYPE (ARG_SYSRET_ERRNO, ::IARG_SYSRET_ERRNO, INT32);

//DEFINE_ARG_TYPE (ARG_SYSARG_CALLSITE_VALUE, ::IARG_SYSARG_CALLSITE_VALUE, ADDRINT);
//DEFINE_ARG_TYPE (ARG_SYSARG_CALLSITE_REFERENCE, ::IARG_SYSARG_CALLSITE_REFERENCE, ADDRINT *);

DEFINE_ARG_TYPE (ARG_RETURN_IP, ::IARG_RETURN_IP, ADDRINT);
DEFINE_ARG_TYPE (ARG_ORIG_FUNCPTR, ::IARG_ORIG_FUNCPTR, AFUNPTR);
DEFINE_ARG_TYPE (ARG_PRESERVE, ::IARG_PRESERVE, REGSET *);

DEFINE_ARG_TYPE (ARG_CALL_ORDER, ::IARG_CALL_ORDER, CALL_ORDER);
DEFINE_ARG_TYPE (ARG_REG_NAT_VALUE, ::IARG_REG_NAT_VALUE, BOOL);

#if defined (TARGET_IA32E)
DEFINE_ARG_TYPE (ARG_REG_OUTPUT_FRAME_VALUE , ::IARG_REG_OUTPUT_FRAME_VALUE , ADDRINT);
DEFINE_ARG_TYPE (ARG_REG_OUTPUT_FRAME_REFERENCE  , ::IARG_REG_OUTPUT_FRAME_REFERENCE , ADDRINT *);
#endif

DEFINE_ARG_TYPE (ARG_IARGLIST, ::IARG_IARGLIST , IARGLIST);

} // namespace Pin
} // namespace OASIS

#endif  // _OASIS_PIN_ARG_H_
