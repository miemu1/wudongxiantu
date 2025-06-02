#pragma save_binary
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

string do_wear();
void create()
{
	set_name(HIR"����֮��"NOR, ({"y4 boots"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "���鼶��[����]֮��\n");
		set("material", "boots");    //����
	set("armor_prop/armor", random(50)+3420);  //����
	set("armor_prop/warm", 3);   //��ů
		set("value", 40);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ

       ///---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","����ʥ��");
		set("suit_mod/finger","����֮��");
		set("suit_mod/boots","����֮��");
//		set("suit_mod/hands","����֮��");
		set("suit_mod/head","��������");
		set("suit_mod/neck","���黤��");
		set("suit_mod/pants","���黤��");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(4)+27);      //����
		set("suit_eff/constitution",random(4)+26);       // ��� 
		set("suit_eff/intelligence",random(4)+25);      //����  
		set("suit_eff/strength",random(4)+26);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",30);   //һ��
		set("suit_eff_skill/dodge",45);
		set("suit_eff_skill/parry",45);

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