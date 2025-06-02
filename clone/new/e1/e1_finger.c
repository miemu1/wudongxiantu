// langren_finger.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

string do_wear();

void create()
{
	set_name(HIR "������˽�ָ" NOR, ({"langren finger"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "���߼���[�������]��ָ\n");
		set("material", "finger");    //����
	set("armor_prop/armor", random(40)+20);  //����
	set("armor_prop/warm", 1);   //��ů
		set("value", 1000);   //��ֵ
		set("wear_msg", (: do_wear :));  //װ����Ϣ
		set("icon","03002");
		  set("suit_point",500);
	//---------------------------------------------------------------
	      //��װ����
		 set("suit",HIR"�������"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","������˵���");
		set("suit_mod/finger","������˽�ָ");
		set("suit_mod/blade","�������̫��");
//		set("suit_mod/hands","�����������");
		set("suit_mod/head","������˶���");
		set("suit_mod/neck","������˻���");
		set("suit_mod/pants","������˻���");			     
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",random(2)+2);       //����
		set("suit_eff/spirituality",random(2)+2);      // ��� 
		set("suit_eff/intelligence",random(2)+2);      //����  
		set("suit_eff/strength",random(2)+2);      //    һ��  
	       //��װȫ�����Ӽ���Ч��   
		set("suit_eff_skill/blade",10);   //һ��
		set("suit_eff_skill/parry",10);
	   
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
