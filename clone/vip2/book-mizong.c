#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"���ھ���"NOR, ({ "mzjishu"}));
	set("long","����һ��"HIG"���ھ���"NOR"��ʹ������Ϊ0��360"ZJURL("cmds:kan mzjishu")+ZJSIZE(28)+"�о�"NOR"��\n");
	set("unit","��");
	set_weight(100);
	set("value",30000);
	set("yuanbao",250);	
    set("no_steal",1);
	set("desc","���ھ���");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="mzjishu")
  	return notify_fail("��Ҫ��ʲô?\n");
      		
 if(me->query_skill("lamaism") < 0)
			return notify_fail("������ڵ���֪̫���� ��\n");
 
 if(me->query_skill("lamaism") > 359)
			return notify_fail("���ھ����Ѿ��ﲻ�� ��\n");

  me->set_skill("lamaism", me->query_skill("lamaism",1) + 25);

	write(HIY"���о�"HIG"���ھ���"HIY"ˢ�����Լ������ڵ���֪!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }