// wusheng_pants.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

string do_wear();

void create()
{
	set_name(HIR "�����Ȱ�-ŷ��" NOR, ({"oyy1 pants"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "а�񼶵�[�����Ȱ�-ŷ��]\n");
		set("material", "pants");    //����
	set("armor_prop/armor", random(50)+170);  //����
	set("armor_prop/warm", 1);   //��ů   �����еģ����û����
		set("value", 10);   //��ֵ
		set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05083");
		  set("suit_point",500);
	 //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����-ŷ��"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������װ-ŷ��");
		set("suit_mod/finger","����֮��-ŷ��");
		set("suit_mod/boots","��������-ŷ��");
//		set("suit_mod/hands","����֮��-ŷ��");
		set("suit_mod/head","����ͷ��-ŷ��");
		set("suit_mod/neck","����֮��-ŷ��");
		set("suit_mod/pants","�����Ȱ�-ŷ��");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(1)+7);      //����
		set("suit_eff/constitution",random(1)+7);       // ��� 
		set("suit_eff/intelligence",random(1)+7);      //����  
		set("suit_eff/strength",random(1)+9);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   

		set("suit_eff_skill/dodge",15);
		set("suit_eff_skill/parry",15);
		set("suit_eff_skill/force",15);
		set("suit_eff_skill/lingshe-zhangfa",9);
		set("suit_eff_skill/hamagong",10);
		set("suit_eff_skill/shedu-qiqiao",15);

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
