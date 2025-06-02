// wusheng_neck.c

#include <ansi.h>
#include <armor.h>

inherit NECK;

string do_wear();

void create()
{
	set_name(HIR "����֮��-÷ׯ" NOR, ({"mzy1 neck"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "а�񼶵�[����֮��-÷ׯ]\n");
		set("material", "neck");    //����
	set("armor_prop/armor", random(50)+170);  //����
	set("armor_prop/warm", 1);   //��ů
	       set("value", 10);   //��ֵ
		 set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05085");
		  set("suit_point",500);
       //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����-÷ׯ"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������װ-÷ׯ");
		set("suit_mod/finger","����֮��-÷ׯ");
		set("suit_mod/boots","��������-÷ׯ");
//		set("suit_mod/hands","����֮��-÷ׯ");
		set("suit_mod/head","����ͷ��-÷ׯ");
		set("suit_mod/neck","����֮��-÷ׯ");
		set("suit_mod/pants","�����Ȱ�-÷ׯ");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(1)+10);      //����
		set("suit_eff/constitution",random(1)+10);       // ��� 
		set("suit_eff/intelligence",random(1)+10);      //����  
		set("suit_eff/strength",random(1)+9);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",10);   //һ��
		set("suit_eff_skill/dodge",15);
		set("suit_eff_skill/parry",15);
		set("suit_eff_skill/sword",15);
		set("suit_eff_skill/xuantian-wujigong",11);
		set("suit_eff_skill/meihua-zhuang",8);
		set("suit_eff_skill/qixian-wuxingjian",15);

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
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "������ǰ����̬����֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ����������ǰ��\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "������ǰ�����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "������ǰ��\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "����һ�ӣ���$n" HIC "������ǰ����������֮����\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "��$n" HIG "չ����������ǰ��\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "��$n" YEL "������ǰ�����˳��½ǣ����������ӡ�\n";
		else    msg = YEL "$N" YEL "ë��ë�ŵİ�$n" YEL "������ǰ�����������\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}
