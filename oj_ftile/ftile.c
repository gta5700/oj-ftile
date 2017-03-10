/*-------------------------------------------------------------------------
 *

 *
 *-------------------------------------------------------------------------
 */
#include "postgres.h"
#include "utils/builtins.h"
#include "windowapi.h"


PG_MODULE_MAGIC;
PG_FUNCTION_INFO_V1(ftile);
Datum ftile(PG_FUNCTION_ARGS);



typedef struct
{
	//  GTA
	int32   group_size;
} divide_context;


 
Datum ftile(PG_FUNCTION_ARGS)
{
	WindowObject winobj = PG_WINDOW_OBJECT();
	int64		curpos = WinGetCurrentPosition(winobj);	
	
	divide_context *context  = (divide_context *)
        WinGetPartitionLocalMemory(winobj, sizeof(divide_context));	
		
	if (context->group_size == 0)
	{
		/* first call */
		int32		group_size;
		bool		isnull;
  
		//  pobranie pierwszego parametru
		group_size = DatumGetInt32(WinGetFuncArgCurrent(winobj, 0, &isnull));

		/*
		 * per spec: If group_size is the null value, then the result is the null
		 * value.
		 */
		if (isnull) {
			context->group_size = -1;
			WinSetMarkPosition(winobj, curpos);
			PG_RETURN_NULL();
		}
		
		if (group_size <= 0)
        elog(ERROR, "invalid group_size: argument of divide must be greater than zero");

    context->group_size = group_size;	
	}
	

	WinSetMarkPosition(winobj, curpos);
	if (context->group_size == -1)
    PG_RETURN_NULL(); 
    
	PG_RETURN_INT64((curpos / context->group_size)+1);
} 

