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
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"请输入GM码：钻石"NOR,"GMma1 $txt#")+"\n");
	    switch (arg) {
	    case "钻石" :
		me->add_temp("sword",1);
		write("哦豁！\n");
		message("vision","GM码正确，钻石+1颗！"+me->name()+"！\n",me);
		
		break;
	  default :
		return notify_fail("GM码错误，钻石-999999颗\n");

	}		
              sscanf(arg, "%s ", a);

  if(me->query("combat_exp")>2100000000)
	{
		tell_object(me, HIR"你的修为超过21亿，无法领取！\n"NOR);
        return 1;
	}

  if(me->query("GM/GMma1")>0)
	{
		tell_object(me, HIR"每个礼包码只能使用一次！\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "领取了钻石+1颗！"NOR);
	me->add("dajif",1);

	me->set("GM/GMma1",1);
//		ob = new("clone/libao/xinshou/kuilei");
//	    ob->move(me);
//		ob = new("clone/zhanling/tianxiang");
//      ob->set_amount(10);
//	    ob->move(me);
	write("GM码正确!\n");
        tell_object(me,HIW"你获得了：\n" +
        1 + "颗钻石\n" +


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
