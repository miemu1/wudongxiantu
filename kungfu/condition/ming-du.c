#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "ming-du"; }

string chinese_name() { return "溟毒"; }

string update_msg_others()
{
       return HIR "$N一声惨嚎，内息逆流，“哇”的一声喷出一大口鲜血。"NOR"\n";
}

string update_msg_self()
{
	return HIR "你只感到五脏六腑翻腾不止，剧毒攻心，看来是中了溟毒的干扰！"NOR"\n";
}

