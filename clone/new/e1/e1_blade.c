#pragma save_binary
#include <weapon.h> 
#include <ansi.h>

inherit BLADE;


void create()
{
	set_name(HIR"�������̫��"NOR, ({"langren blade"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѳ�֪��ʲô��������̫�����������ĵĹ�â\n");
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
	init_blade(random(40)+80);
	setup();
}

int query_autoload()
{
	return 1;
}

