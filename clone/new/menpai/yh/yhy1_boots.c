#pragma save_binary
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

string do_wear();
void create()
{
	set_name(HIR"��������-�ƻ�"NOR, ({"yhy1 boots"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "а�񼶵�[��������-�ƻ�]\n");
		set("material", "boots");    //����
	set("armor_prop/armor", random(20)+230);  //����
	set("armor_prop/warm", 3);   //��ů
		set("value", 10);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ

       //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����-�ƻ�"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������װ-�ƻ�");
		set("suit_mod/finger","����֮��-�ƻ�");
		set("suit_mod/boots","��������-�ƻ�");
//		set("suit_mod/hands","����֮��-�ƻ�");
		set("suit_mod/head","����ͷ��-�ƻ�");
		set("suit_mod/neck","����֮��-�ƻ�");
		set("suit_mod/pants","�����Ȱ�-�ƻ�");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(2)+10);      //����
		set("suit_eff/constitution",random(1)+9);       // ��� 
		set("suit_eff/intelligence",random(3)+10);      //����  
		set("suit_eff/strength",random(1)+6);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",10);   //һ��
		set("suit_eff_skill/dodge",15);
		set("suit_eff_skill/parry",15);

		set("suit_eff_skill/mingyu-shengong",18);
		set("suit_eff_skill/yihua-jiemu",10);
		set("suit_eff_skill/yifeng-jian",15);

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