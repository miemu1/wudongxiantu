#pragma save_binary
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

string do_wear();
void create()
{
	set_name(HIR"��������-��Ĺ"NOR, ({"gmy1 boots"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "а�񼶵�[��������-��Ĺ]\n");
		set("material", "boots");    //����
	set("armor_prop/armor", random(50)+180);  //����
	set("armor_prop/warm", 3);   //��ů
		set("value", 10);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ

        //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����-��Ĺ"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������װ-��Ĺ");
		set("suit_mod/finger","����֮��-��Ĺ");
		set("suit_mod/boots","��������-��Ĺ");
//		set("suit_mod/hands","����֮��-��Ĺ");
		set("suit_mod/head","����ͷ��-��Ĺ");
		set("suit_mod/neck","����֮��-��Ĺ");
		set("suit_mod/pants","�����Ȱ�-��Ĺ");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(1)+4);      //����
		set("suit_eff/constitution",random(1)+7);       // ��� 
		set("suit_eff/intelligence",random(1)+7);      //����  
		set("suit_eff/strength",random(1)+9);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",10);   //һ��
		set("suit_eff_skill/dodge",15);
		set("suit_eff_skill/parry",15);
		set("suit_eff_skill/sword",15);
		set("suit_eff_skill/yunv-xinjing",17);
		set("suit_eff_skill/xuantie-jian",15);

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