#include <ansi.h>

inherit ITEM;

void create()
{
	set_name (HIG"��������"NOR, ({ "bagua"}));
	set("long","����һ��"HIG"��������"NOR"��ʹ������Ϊ250��360"ZJURL("cmds:kan bagua")+ZJSIZE(28)+"�о�"NOR"��\n");
	set("unit","��");
	set_weight(100);
	set("value",30000);
	set("yuanbao",50);	
    set("no_steal",1);
	set("desc","��������");
	setup();
}

void init()
{
	add_action("do_kan","kan");

}

int do_kan(string arg)
{
	object me=this_player();


	if (arg!="bagua")
  	return notify_fail("��Ҫ��ʲô?\n");
      		
 if(me->query_skill("count") < 120)
			return notify_fail("����������Ե���֪̫���� ��\n");
 
 if(me->query_skill("count") > me->query_skill("mathematics"))
			return notify_fail("�����������֪̫���� ��\n");
			
 if(me->query_skill("count") > 359)
			return notify_fail("���������Ѿ��ﲻ�� ��\n");

  me->set_skill("count", me->query_skill("count",1) + 1);

	write(HIY"���о�"HIG"��������"HIY"ˢ�����Լ����������Ե���֪!"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }