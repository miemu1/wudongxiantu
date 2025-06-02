#pragma save_binary
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

string do_wear();
void create()
{
	set_name(HIY"ʷʫ֮��"NOR, ({"y3 boots"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "ʷʫ����[ʷʫ]֮��\n");
		set("material", "boots");    //����
	set("armor_prop/armor", random(50)+970);  //����
	set("armor_prop/warm", 3);   //��ů
		set("value", 30);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ

       //---------------------------------------------------------------
	      //��װ����//---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"ʷʫ"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","ʷʫʥ��");
		set("suit_mod/finger","ʷʫ֮��");
		set("suit_mod/boots","ʷʫ֮��");
//		set("suit_mod/hands","ʷʫ֮��");
		set("suit_mod/head","ʷʫ���");
		set("suit_mod/neck","ʷʫ����");
		set("suit_mod/pants","ʷʫ����");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(4)+15);      //����
		set("suit_eff/constitution",random(4)+15);       // ���
		set("suit_eff/intelligence",random(4)+15);      //����
		set("suit_eff/strength",random(4)+15);      //    һ��
	       //��װȫ�����Ӽ���Ч��
		set("suit_eff_skill/force",20);   //һ��
		set("suit_eff_skill/dodge",27);
		set("suit_eff_skill/parry",27);

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