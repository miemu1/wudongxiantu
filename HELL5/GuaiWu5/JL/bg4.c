// m_jia.c

#include <ansi.h>

#include <armor.h>

inherit S_RING;


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
	w_id = "my "+me->query("jiajiajia/id");
	w_or = me->query("jiajia/or");
	w_lv = me->query("jiajia/lv");
	lv1=me->query("jinjie/s1")*500;
	lv2=me->query("guizhen")*1000+me->query("zhengdao/s1")*100000+me->query("feisheng/s1")*50000000;
	
	lv3=(me->query("jinjie/s2"));		
        if (!me->query("jiajia/name"))
        {
	w_name=HIC "���롤��ָ" NOR;
        }
        if (!me->query("jiajiajia/id"))
        {
	w_id="Huo Lin4";
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
		set("long", HIC"�������޶���"NOR"����ϵ��								
"HIG"����װ�ӳɣ������ɾ��ȼ�+75��������750��"NOR"\n");
	set("value",1000);
	set("armor_prop/armor", 75);
	set("armor_prop/unarmed_damage", 75+lv1+lv2+lv3);
	set("armor_prop/damage", 75+lv1+lv2+lv3);	
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
	set("armor_type","finger");
		set("material", "fur");
				 set("suit",HIR"������װ"NOR);  //��װ����
		set("suit_lvl",7);	     //��װ�ȼ�
		set("suit_count",9);	   //��װ��������
	      //��װ������
		set("suit_mod/arrmor","���롤����");
		set("suit_mod/finger","���롤��ָ");
//		set("suit_mod/hands","���롤����");
		set("suit_mod/head","���롤ͷ��");
		set("suit_mod/neck","���롤����");
		set("suit_mod/pants","���롤����");
		set("suit_mod/boots","���롤��ѥ");
		set("suit_mod/cloth","���롤�·�");
//		set("suit_mod/surcoat","���롤����");
//		set("suit_mod/shield","���롤����");
		set("suit_mod/waist","���롤����");
		set("suit_mod/wrists","���롤����");
	    //��װȫ�������츳Ч��  //����һ�����ǵڶ������Ե�������������
		set("suit_eff/constitution",5);      //3��
		set("suit_eff/spirituality",5);      // 5��
		set("suit_eff/intelligence",5);      //7��
		set("suit_eff/strength",5);      //9��
	       //��װȫ�����Ӽ���Ч����һ����
        set("suit_eff_skill/badao",75+me->query("taozhuang/lv"));
	setup();
}



