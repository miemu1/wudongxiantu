// wusheng_hands.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

string do_wear();

void create()
{
	set_name(HIR "ʥ��֮��" NOR, ({"y5 hands"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "ʥ�鼶��[ʥ��]֮��\n");
		set("material", "neck");    //����
	set("armor_prop/armor", random(799)+6200);  //����
	set("armor_prop/unarmed_damage", random(99)+300);
	set("armor_prop/warm", 1);   //��ů
	       set("value", 50);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05084");
		  set("suit_point",500);
		///---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","ʥ��ʥ��");
		set("suit_mod/finger","ʥ��֮��");
		set("suit_mod/boots","ʥ��֮��");
//		set("suit_mod/hands","ʥ��֮��");
		set("suit_mod/head","ʥ������");
		set("suit_mod/neck","ʥ�黤��");
		set("suit_mod/pants","ʥ�黤��");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(4)+40);      //����
		set("suit_eff/constitution",random(4)+45);       // ��� 
		set("suit_eff/intelligence",random(4)+47);      //����  
		set("suit_eff/strength",random(4)+50);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",55);   //һ��
		set("suit_eff_skill/dodge",67);
		set("suit_eff_skill/parry",67);

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
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "�������ϣ���̬����֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�����������ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "�������ϣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "�������ϡ�\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "����һ�ӣ���$n" HIC "�������ϣ���������֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ�����������ϡ�\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "�������ϣ����˳��½ǣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "�������ϣ����������\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
