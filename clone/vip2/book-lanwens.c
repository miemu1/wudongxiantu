#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"���ľ���"NOR, ({ "lanwens"}));
	set("long","����һ��"HIG"���ľ���"NOR"��ʹ������Ϊ0��360"ZJURL("cmds:kan lanwens")+ZJSIZE(28)+"�о�"NOR"��\n");
	set("unit","��");
	set_weight(100);
	set("value",30000);
	set("yuanbao",250);	
    set("no_steal",1);
	set("desc","���ľ���");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="lanwens")
  	return notify_fail("��Ҫ��ʲô?\n");
      		
 if(me->query_skill("sanscrit") < 0)
			return notify_fail("������ĵ���֪̫���� ��\n");
 
 if(me->query_skill("sanscrit") > 359)
			return notify_fail("���ľ����Ѿ��ﲻ�� ��\n");

  me->set_skill("sanscrit", me->query_skill("sanscrit",1) + 25);

	write(HIY"���о�"HIG"���ľ���"HIY"ˢ�����Լ������ĵ���֪!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }