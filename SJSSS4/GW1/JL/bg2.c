// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_BOOTS;


int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
        add_action("do_duanlian","lianjia");
	add_action("do_hui","huijia");
	add_action("do_levelup","jijia");
}


void create()
{
	object me;
	string w_name,w_id,w_or;
	int w_lv;
	int lv1,lv2,lv3;
	
	me = this_player();
//��������
	w_name=me->query("jiajia/name");
	w_id = "my "+me->query("jiajia/id");
	w_or = me->query("jiajia/or");
	w_lv = me->query("jiajia/lv");
	lv1=me->query("jinjie/s1")*100;
	lv2=me->query("guizhen")*1000+me->query("zhengdao/s1")*100000+me->query("feisheng/s1")*10000000;
	
	lv3=(me->query("jinjie/s2"));		
        if (!me->query("jiajia/name"))
        {
	w_name=HIY "ԪӤ����ѥ" NOR;
        }
        if (!me->query("jiajia/id"))
        {
	w_id="Jie Dans2";
        }
        if (!me->query("jiajia/or"))
        {
	w_or="ǧ����ľ";
        }
        if (!me->query("jiajia/lv"))
        {
	w_lv=1;
        }
        if (me->query("jiajia/lv",1) > 200)
        {
	w_lv=200;
        }

		set("material", "boots");    //����
				 set("material", "crimson gold");  //ԭ��

	set_name(w_name, ({w_id}));
	set("unit", "��");
		set("long", HIC"��ԪӤ�޶���"NOR"ԪӤϵ��								
"HIG"����װ�ӳɣ������淨�ȼ�+250��������40000��"NOR"\n");
	set("value",1000);
	set("armor_prop/armor", 4000);
	set("armor_prop/leech_qi", 1);
	set("armor_prop/reduce_poison", 1);
	set("armor_prop/reduce_magic", 1);
	set("armor_prop/unarmed_damage", 4000+lv1+lv2+lv3);
	set("armor_prop/damage", 4000+lv1+lv2+lv3);	
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("armor_prop/baoji", w_lv * 2);
	set("no_sell",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);

	switch(w_or)
		{
		case "ǧ����ľ" :
			set_weight(500);
			set("material", "fur");
			break;
		case "���׽�ĸ" :
			set_weight(1000);
			set("material", "fur");
			break;
		case "��˿����" :
			set_weight(500);
			set("material", "fur");
			break;
		default :
		}
	set("unit", "��");
	if( me->query("jia/wear_msg"))
		set("wear_msg", me->query("jia/wear_msg")+"\n");
	else
		set("wear_msg", "$N����"+w_name+"�����ϡ�\n");
	if( me->query("jia/unequip_msg"))
		set("unequip_msg", me->query("jia/unequip_msg")+"\n");
	else
		set("unequip_msg", "$N���ϵ�"+w_name+"����������գ�ۼ���Ȼ����Ӱ�١�\n");
	set("armor_type","boots");
				 set("suit",HIR"ԪӤ��װ"NOR);  //��װ����
		set("suit_lvl",6);	     //��װ�ȼ�
		set("suit_count",9);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","ԪӤ������");
		set("suit_mod/finger","ԪӤ����ָ");
		set("suit_mod/head","ԪӤ��ͷ��");
		set("suit_mod/neck","ԪӤ������");
		set("suit_mod/pants","ԪӤ������");
		set("suit_mod/boots","ԪӤ����ѥ");
		set("suit_mod/cloth","ԪӤ���·�");
		set("suit_mod/waist","ԪӤ������");
		set("suit_mod/wrists","ԪӤ������");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",random(20)+10);      //3��
		set("suit_eff/spirituality",random(20)+10);      // 5��
		set("suit_eff/intelligence",random(20)+10);      //7��
		set("suit_eff/strength",random(20)+40);      //9��
	       //��װȫ�����Ӽ���Ч����һ����
		set("suit_eff/constitution",40);      //3��
		set("suit_eff/spirituality",40);      // 5��
		set("suit_eff/intelligence",40);      //7��
		set("suit_eff/strength",40);      //9��
	       //��װȫ�����Ӽ���Ч����һ����
        set("suit_eff_skill/xiuxian-gongfa",250+me->query("taozhuang/lv"));
	setup();
}




