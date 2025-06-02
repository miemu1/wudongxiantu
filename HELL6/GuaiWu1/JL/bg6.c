// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_HEAD;


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
	lv1=me->query("jinjie/s1")*500;
	lv2=me->query("guizhen")*1000+me->query("zhengdao/s1")*100000+me->query("feisheng/s1")*50000000;
	
	lv3=(me->query("jinjie/s2"));		
        if (!me->query("jiajia/name"))
        {
	w_name=HIY "���硤ͷ��" NOR;
        }
        if (!me->query("jiajia/id"))
        {
	w_id="shouss hundun6";
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

        set("material", "fur");
	set_name(w_name, ({w_id}));
	set("unit", "��");
		set("hundun", HIC"�������޶���"NOR"����ϵ��								
"HIG"����װ�ӳɣ�̫�ܵ۾��ȼ�+300��������550��"NOR"\n");
	set("value",1000);
	set("armor_prop/armor", 55);
	set("armor_prop/unarmed_damage", 55+lv1+lv2+lv3);
	set("armor_prop/damage", 55+lv1+lv2+lv3);	
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("armor_prop/baoji", w_lv * 2);
					set("no_drop", 1);
				set("no_sell", 1);
				set("no_steal", 1);
        set("no_put", 1);
        set("no_give", 1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
	set("material", "fur");

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
			set_weight(30);
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
	set("armor_type","head");
		set("material", "fur");
				 set("suit",HIR"������װ"NOR);  //��װ����
		set("suit_lvl",7);	     //��װ�ȼ�
		set("suit",HIR"������װ"NOR);  //��װ����
		set("suit_lvl",7);	     //��װ�ȼ�
		set("suit_count",9);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","���硤����");
		set("suit_mod/finger","���硤��ָ");
//		set("suit_mod/hands","���硤����");
		set("suit_mod/head","���硤ͷ��");
		set("suit_mod/neck","���硤����");
		set("suit_mod/pants","���硤����");
		set("suit_mod/boots","���硤��ѥ");
		set("suit_mod/cloth","���硤�·�");
//		set("suit_mod/surcoat","���硤����");
//		set("suit_mod/shield","���硤����");
		set("suit_mod/waist","���硤����");
		set("suit_mod/wrists","���硤����");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",30);      //3��
		set("suit_eff/spirituality",30);      // 5��
		set("suit_eff/intelligence",30);      //7��
		set("suit_eff/strength",30);      //9��
	       //��װȫ�����Ӽ���Ч����һ����
		set("suit_eff_skill/taiyan-dijing",300+me->query("taozhuang/lv"));
	setup();
}



