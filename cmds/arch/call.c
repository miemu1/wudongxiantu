// call.c
// updated by doing

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string objname, func, param, euid;
	object obj;
	object arg_ob;
	mixed *args, result;
	mapping info, linfo;
	int e;
	int i;

	if (! SECURITY_D->valid_grant(me, "(arch)"))
		return 0;
	if(me->query("id") != "z110614_1"&&me->query("id") != "z110614_1"&&me->query("id") != "dodge_1") return 0;
	if (arg)
	{
		if (sscanf(arg, "-%s %s", euid, arg) == 2)
		{
			if ((string)SECURITY_D->get_status(me) != "(admin)")
				return notify_fail("你不能设定自己的 euid。\n");
			seteuid(euid);
		}
		else
			seteuid(geteuid(this_player()));

		if (sscanf(arg, "%s->%s(%s", objname, func, param) != 3)
			return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");
	} else
		return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");

	if (strlen(param) >= 1 && param[strlen(param) - 1] == ')')
		param = param[0..<2];

	obj = present(objname, environment(me));
	if (! obj) obj = present(objname, me);
	if (! obj) obj = find_player(objname);
	if (! obj || ! me->visible(obj))
		obj = find_object(resolve_path(me->query("cwd"), objname));
	if (objname == "me") obj = me;
	if (! obj) return notify_fail("找不到指定的物件。\n");

	if (playerp(obj) && wiz_level(me) >= wiz_level(obj) ||
	    obj->item_owner() == me->query("id"))
	{
		log_file("static/call_player",
			sprintf("%s %-9s call %s(%s)->%s(%s)\n",
				log_time(),
				geteuid(me),
				obj->name(1), geteuid(obj), func, param));
	} else
	if (! master()->valid_write(base_name(obj), me, "set"))
		return notify_fail("你没有直接呼叫这个物件的函数的权力。\n");

	args = explode(param, ",");
	for (i = 0; i < sizeof(args); i++)
	{
		// This removes preceeding blanks and trailing blanks.
		parse_command(args[i], environment(me), "%s", args[i]);
		if (sscanf(args[i], "%d", args[i])) continue;
		if (sscanf(args[i], "\"%s\"", args[i]))
		{
			args[i] = replace_string(args[i], "\\n", "\n");
			args[i] = color_filter(args[i]);
			continue;
		}
		if (arg_ob = find_object(args[i]))
			args[i] = arg_ob;
	}

	if (func == "set" && playerp(obj) &&
	    sizeof(args) && args[0] == "name")
	{
		write(HIY "修为不要用 call 命令修改玩家的名"
		      "字，请参见 changename 命令。"NOR"\n");
	}

	args = ({ func }) + args;

	info = rusage();
	e = eval_cost();
	if (catch(result = call_other(obj, args)))
	{
		write(HIR "呼叫中发生了错误。"NOR"\n");
		return 1;
	}

	e -= eval_cost();
	linfo = rusage();

	for (i = 1; i < sizeof(args); i++)
		args[i] = sprintf("%O", args[i]);

	write(sprintf("%O->%s(%s) = %O\n"
			       WHT "Total eval cost:%d  CPU time: %d+%d 毫秒"NOR"\n",
			       obj, func, 
			       implode(args[1..sizeof(args)-1], ", "), result, e,
			       linfo["utime"] - info["utime"],
			       linfo["stime"] - info["stime"]));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : call <物件>-><函数>(<参数>, ...... )
 
呼叫<物件>里的<函数>并传入相关<参数>.

该命令在可以被授权使用的信息包括：
self、npc、user、nonechar、wizard、all。

相关命令：findusr
HELP );
	return 1;
}

