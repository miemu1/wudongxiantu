// wusheng_finger.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

string do_wear();

void create()
{
	set_name(HIY "ʷʫ֮��" NOR, ({"y3 finger"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "ʷʫ����[ʷʫ]֮��\n");
		set("material", "finger");    //����
	set("armor_prop/armor", random(50)+1400);  //����
	set("armor_prop/unarmed_damage", random(40)+20);
	set("armor_prop/warm", 1);   //��ů
		set("value", 30);   //��ֵ
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","03002");
		  set("suit_point",500);
		//---------------------------------------------------------------
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
