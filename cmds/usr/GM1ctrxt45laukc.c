// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
object obj,ob;
int count,mengxin;
string a;
me = this_player();
CHANNEL_D->do_channel(this_object(),"rumor",
HIY+me->name() + "领取了点券+1张！"NOR);
me->add("jifeng",1);
write("GM码正确!\n");
tell_object(me,HIW"你获得了：\n" +
1 + "张点券\n" +
NOR);
return 1;
}
int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}
