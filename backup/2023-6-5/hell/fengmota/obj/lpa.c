//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIM"����"NOR, ({"lpa"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ֵ�����(lpa)������(dapo)�����Խ����ħ����\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  add_action("do_dapo", "dapo");
}

int do_dapo(string arg)
{
  object me = this_player();
  object ob;

  if (arg!="lpa")   return 0;
     ob = new("/data/hell/fengmota/npc/guiwang");
        ob->move(environment(me));
        message_vision(CYN"$N�������ƣ�����ǰ��Ȼ����һ��ģ���������Ӱ��\n",me);  
        write("�����������ӭ������ħ������ս�ߡ���\n");
		write("������������Ƿ�ħ�������飬��Ҫ�����ħ�������������ҵĿ��顣��\n");
        write("�����������׼�������룿�����ǿ�ʼ�ɣ�������\n"NOR);
        destruct(this_object());
        return 1;
}

