#pragma save_binary
#include <weapon.h>
#include <ansi.h>

inherit WHIP;


void create()
{
	set_name(HIG"�鶯����"NOR, ({"lingdong whip"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѳ�֪��ʲô�������ĳ��ޣ��������ĵĹ�â\n");
		set("value", 2000);   //��ֵ
		 set("material", "crimson gold");  //ԭ��
		set("wield_msg",
"$N��ৡ���һ�����һ��$n�������У�\n");
		set("unwield_msg",
"$N�����е�$n�������䣬���¶��һ˿Ц�⣮\n");
	 set("weapon_prop/int", 2);
	 set("icon","05093");
	    set("suit_point",1000);
       //---------------------------------------------------------------
	      //��װ����
		 set("suit",HIG"�鶯"NOR);  //��װ����
		set("suit_lvl",5);	     //��װ�ȼ�
		set("suit_count",7);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","�鶯����");
		set("suit_mod/finger","�鶯ָ��");
		set("suit_mod/whip","�鶯����");
//		set("suit_mod/hands","�鶯����");
		set("suit_mod/head","�鶯����");
		set("suit_mod/neck","�鶯����");
		set("suit_mod/pants","�鶯�ȼ�");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",random(2)+2);       //����
		set("suit_eff/spirituality",random(2)+2);      // ���
		set("suit_eff/intelligence",random(2)+2);      //����
		set("suit_eff/strength",random(2)+2);      //    һ��
	       //��װȫ�����Ӽ���Ч��
		set("suit_eff_skill/whip",10);   //һ��
		set("suit_eff_skill/dodge",10);
       //---------------------------------------------------------------
	}
	init_whip(random(40)+80);
	setup();
}

int query_autoload()
{
	return 1;
}

