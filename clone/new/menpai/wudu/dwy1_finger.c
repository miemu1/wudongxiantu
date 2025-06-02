// wusheng_finger.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

string do_wear();

void create()
{
	set_name(HIR "����֮��-����" NOR, ({"dsy1 finger"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "а�񼶵�[����֮��-����\n");
		set("material", "finger");    //����
	set("armor_prop/armor", random(50)+150);  //����
	set("armor_prop/unarmed_damage", random(40)+20);
	set("armor_prop/warm", 1);   //��ů
		set("value", 10);   //��ֵ
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","03002");
		  set("suit_point",500);
	 //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����-�嶾"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������װ-����");
		set("suit_mod/finger","����֮��-����");
		set("suit_mod/boots","��������-����");
//		set("suit_mod/hands","����֮��-����");
		set("suit_mod/head","������ñ-����");
		set("suit_mod/neck","����֮��-����");
		set("suit_mod/pants","�����ȼ�-����");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(1)+7);      //����
		set("suit_eff/constitution",random(1)+4);       // ���
		set("suit_eff/intelligence",random(1)+6);      //����
		set("suit_eff/strength",random(1)+8);      //    һ��
	       //��װȫ�����Ӽ���Ч��
		set("suit_eff_skill/force",10);   //һ��
		set("suit_eff_skill/whip",15);
		set("suit_eff_skill/hand",15);
		set("suit_eff_skill/xiuluo-yinshagong",10);
		set("suit_eff_skill/ruanhong-zhusuo",15);
		set("suit_eff_skill/qianzhu-wandushou",15);

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
