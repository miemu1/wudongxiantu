#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

	if(environment(me)&&environment(me)->query("owner_special")&&environment(me)->query("sleep_room"))
	        return CND_CONTINUE;
        me->apply_condition("db_exp3", duration - 1);
        
        if( duration < 1 ) 
        {
        	tell_object(me, HIR"你觉得精神有些疲惫，麒麟丹效果失效，成长速度又慢了下来。"NOR"\n");
        	return 0;
        }
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "db_exp3";
}
