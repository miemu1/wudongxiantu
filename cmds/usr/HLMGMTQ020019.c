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
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);		
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
		ob = new("SJSSS9/BOX/box1");
        ob->set_amount(1);
	    ob->move(me);	
	write("激活码正确，恭喜你成功激活GM特权!\n");
        tell_object(me,HIW"你获得了：\n" +
        10 + "个 渡劫宝箱\n" +
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
