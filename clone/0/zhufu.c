// dragon-blade ������
// Modifyied by rock

//#include <weapon.h>
#include <ansi.h>
inherit ITEM;

// �������������
int query_xy() { return 1 ; }


int do_training(string arg);


void create()
{
        set_name(HIY HIM"ף"HIY"��"HIW"��"RED"ʯ" NOR,({ "zhufu stone", "zhufu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", HIW "����һ����ʱ�޿���Ϊ���ȡ��ΪǱ�ܣ����������书�ı�ʯ,""\n""����("ZJURL("cmds:xunlian exp")ZJSIZE(20)""HIY"����ģʽ"NOR")""--""("ZJURL("cmds:xunlian over")ZJSIZE(20)""HIY"����"NOR")\n" NOR);
		set("no_drop", "�������������뿪�㡣\n");
		set("no_put",1);
		set("no_sell",1);
		set("no_save",1);
		set("no_give",1);
		set("nopaimai",1);
		set("no_get",1);
		set("credit",500);
        set("value", 100000);
		set("zhiliang",3);
		set("level",1);
		set("exp",5000);
		set("weapon_prop/baoji",10000);
                set("material", "magic");
                set("_level",20);
                set("jing",100);
                set("jingli",50);
                set("weapon_prop/strength",5);
                set("weapon_prop/dexerity",5);
                set("weapon_prop/intelligence",5);
                set("weapon_prop/constitution",5);

                set("wield_msg", HIY "$N��ৡ���һ�����$n" + HIY + "�����˵���â���£������Ƿɣ���ر�ɫ�� ....$N���ɵô��ĵ�����һ�����ƺ�����\n" NOR);
                set("unwield_msg", HIW "����֮��"HIY"����һ���׹⣬��ৡ��ط��뵶�ʡ�\n" NOR);        }
        	set("max_lasting",100);
        	setup();
}


string check_len(string str)
{
	int max_len = 33,len;

	len = (max_len+color_len(str)) - strlen(str);
	return sprintf("%"+len+"s","��\n");
}

void init()
{
		add_action("do_training", "xunlian");
}

int do_training(string arg)
{
	object me= this_player();

	//if(me->query_temp("weapon") != this_object()) return 0;

	return "/adm/daemons/makeweapon"->call_do_training(me,arg);
}

