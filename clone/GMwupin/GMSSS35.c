// �Ϲ�ʮ������֮ ��ԯ��
// Create by Rcwiz for Hero.cn 2003/09

#include <ansi.h>

#include <armor.h>

inherit ARMOR;
string do_wear();
int is_magic_item() { return 1; }


void create()
{
        set_name(HIG "ħ������" NOR, ({ "mfkai jia" }) );
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
            set("unit", "��");
            set("long", HIG "����ħ�������Դ��Ļ���\n"NOR);
            set("material", "armor");
			set("suit_point",5000);
			set("armor_prop/armor", 5000);
			set("wear_msg", (: do_wear :));
			set("gongxian",100);
			set("no_give",1);
			set("no_steal",1);
			set("no_sell", 1);
			set("no_get",1);
		//	set("no_put",1);
		    set("armor_prop/parry",500);
			set("wear_msg",HIC "$N" HIC "���Ὣһ��$n" HIC "�������ϣ���̬����֮����\n");
			set("remove_msg", HIC "$N" HIC "��������$n" HIC "ֻ��$n��ɢ�����֮�С�\n");
        }
   //     init_sword(21000000);
        setup();
}

string do_wear()
{
	object me;
	string msg;
	int per;

	me = this_player();
	per = me->query("per");
	if (me->query("gender") == "Ů��")
	{
		if (per >= 30)
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "�������ϣ���̬����֮����\n";
		
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "����һ�ӣ���$n" HIC "�������ϣ���������֮����\n";
		
	}
	return msg;
}

int query_autoload()
{
	return 1;
}


