#pragma save_binary
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

string do_wear();
void create()
{
	set_name(HIC"����֮��"NOR, ({"y2 boots"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "���鼶��[����]����\n");
		set("material", "boots");    //����
	set("armor_prop/armor", random(50)+349);  //����
	set("armor_prop/warm", 3);   //��ů
		set("value", 10);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ

       //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","����ʥ��");
		set("suit_mod/finger","����֮��");
		set("suit_mod/boots","���鲽��");
//		set("suit_mod/hands","����֮צ");
		set("suit_mod/head","����ʹ�");
		set("suit_mod/neck","���黤��");
		set("suit_mod/pants","���黤��");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(7)+15);      //����
		set("suit_eff/constitution",random(7)+15);       // ���
		set("suit_eff/intelligence",random(7)+15);      //����
		set("suit_eff/strength",random(7)+15);      //    һ��
	       //��װȫ�����Ӽ���Ч��
		set("suit_eff_skill/force",15);   //һ��
		set("suit_eff_skill/dodge",22);
		set("suit_eff_skill/parry",22);

       //---------------------------------------------------------------
	}
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
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "���ڽ��ϣ���̬����֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�������ڽ��ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "���ڽ��ϣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "���ڽ��ϡ�\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "����һ�ӣ���$n" HIC "���ڽ��ϣ���������֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�������ڽ��ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "���ڽ��ϣ����˳��½ǣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "���ڽ��ϣ����������\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}