// wusheng_arrmor.c

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

string do_wear();

void create()
{
	set_name(HIR "��������" NOR, ({"gzf arrmor"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "��������[����]����\n");
		set("material", "armor");
	set("armor_prop/armor", random(50)+200);  //����
	set("armor_prop/warm", 20);   //��ů
		set("value", 10);   //��ֵ
		 set("material", "crimson gold");  //ԭ��
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","05082");
		set("suit_point",500);
	 //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"����"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","��������");
		set("suit_mod/finger","�������");
		set("suit_mod/boots","��������");
//		set("suit_mod/hands","����֮��");
		set("suit_mod/head","��������");
		set("suit_mod/neck","��������");
		set("suit_mod/pants","����֮��");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/spirituality",random(1)+1);      //����
		set("suit_eff/constitution",random(1)+1);       // ��� 
		set("suit_eff/intelligence",random(1)+25);      //����  
		set("suit_eff/strength",random(1)+1);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/force",7);   //һ��
		set("suit_eff_skill/dodge",7);
		set("suit_eff_skill/parry",8);

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
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ���\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "���Ὣһ��$n" HIG "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ���\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "���Ὣһ��$n" YEL "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ���\n";
		else	
			msg = YEL "$N" YEL "���Ὣһ��$n" YEL "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ���\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "���Ὣһ��$n" HIC "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ���\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "���Ὣһ��$n" HIG "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ�����\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "���Ὣһ��$n" YEL "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ���\n";
		else    
			msg = YEL "$N" YEL "���Ὣһ��$n" YEL "�ó������߾٣�Ц������Ϊ��������ҷ����������Ժ���\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}