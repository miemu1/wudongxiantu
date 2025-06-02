// wusheng_arrmor.c

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

string do_wear();

void create()
{
	set_name(HIR "Զ��ʥ��" NOR, ({"y6 arrmor"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "Զ�ż���[Զ��]ʥ��\n");
		set("material", "armor");
	set("armor_prop/armor", random(800)+9800);  //����
	set("armor_prop/warm", 20);   //��ů
		set("value", 60);   //��ֵ
		 set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05082");
		set("suit_point",500);
	 //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"Զ��"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","Զ��ʥ��");
		set("suit_mod/finger","Զ��֮��");
		set("suit_mod/boots","Զ��֮��");
//		set("suit_mod/hands","Զ��֮��");
		set("suit_mod/head","Զ������");
		set("suit_mod/neck","Զ�Ż���");
		set("suit_mod/pants","Զ�Ż���");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(5)+77);      //����
		set("suit_eff/constitution",random(5)+85);       // ��� 
		set("suit_eff/intelligence",random(5)+88);      //����  
		set("suit_eff/strength",random(5)+90);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",90);   //һ��
		set("suit_eff_skill/dodge",100);
		set("suit_eff_skill/parry",100);

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
