// wusheng_hands.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

string do_wear();

void create()
{
	set_name(HIR "����֮��-Ľ��" NOR, ({"mry1 hands"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "а�񼶵�[����֮��-Ľ��]\n");
		set("material", "neck");    //����
	set("armor_prop/armor", random(50)+180);  //����
	set("armor_prop/unarmed_damage", random(120)+20);
	set("armor_prop/warm", 1);   //��ů
	       set("value", 10);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05084");
		  set("suit_point",500);
	//---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����-Ľ��"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������װ-Ľ��");
		set("suit_mod/finger","����֮��-Ľ��");
		set("suit_mod/boots","��������-Ľ��");
//		set("suit_mod/hands","����֮��-Ľ��");
		set("suit_mod/head","����ͷ��-Ľ��");
		set("suit_mod/neck","����֮��-Ľ��");
		set("suit_mod/pants","�����Ȱ�-Ľ��");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(1)+5);      //����
		set("suit_eff/constitution",random(1)+5);       // ��� 
		set("suit_eff/intelligence",random(1)+9);      //����  
		set("suit_eff/strength",random(1)+6);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",10);   //һ��
		set("suit_eff_skill/dodge",15);
		set("suit_eff_skill/parry",15);

		set("suit_eff_skill/zihui-xinfa",11);
		set("suit_eff_skill/douzhuan-xingyi",8);
		set("suit_eff_skill/murong-jianfa",15);

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
