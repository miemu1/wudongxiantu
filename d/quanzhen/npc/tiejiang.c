// by ranger_����
// Smith.c

inherit NPC;
inherit F_DEALER;
int ask_jianding();

//��������Ϊ����
mapping weapon_sx = ([
	"attack" : 1,
	"damage" : 1,
	"neili" : 5,
]);
mapping armor_sx = ([
	"dodge" : 1,
	"attack" : 1,
	"parry" : 1,
	"armor" : 1,
	"qi" : 10,
	"jing" : 5,
]);
mapping name_sx = ([
	"attack" : "����",
	"damage" : "�˺�",
	"neili" : "����",
	"dodge" : "����",
	"parry" : "�м�",
	"armor" : "����",
	"qi" : "��Ѫ",
	"jing" : "����",
]);

void create()
{
	set_name("��ֵ�����",({"tie jiang","smith"}));
	set("gender","����");
	set("per",18);
	set("age",33);
	set("long","����������ǯ��סһ����ȵ�����Ž�¯�С�");
	set("combat_exp",100);
	set("vendor_goods", ({
		"/clone/cloth/pi",
		"/clone/weapon/sword/biyusword",
		"/clone/weapon/blade/zijinblade", 
		"/clone/weapon/unarmed/zhizhua"
	}) );
	setup();
	set("inquiry", ([
		"����װ��" : (: ask_jianding :),
	]));
}

void init()
{       
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("jianding_b","jianding_b");
}
int jianding_b(string arg)
{
	object me = this_player();
	int mun,i,k;
	mapping sx, all_sx;
	string *list_sx,type,str="",id,stra,bs;
	object obj;
	string sx_a;
	int kk,j=0;
	/*
	if (!wizardp(me))
		return 1;
*/
	if (sscanf(arg, "%s %s", id, bs) != 2)
	{
		if (!objectp(obj = present(arg, me)))
			return notify_fail("������û������������\n");
		
		stra = ZJOBLONG+sprintf("ȷ����Ҫ����"+obj->name()+NOR"��\n");

		stra += ZJOBACTS2+ZJMENUF(2,2,10,30);
		stra += HIG+"ȷ�ϼ���"NOR":jianding_b " + file_name(obj) +" yes"+ZJSEP;
		stra += HIW+"ȡ������"NOR":jianding_b " + file_name(obj) +" no";
		tell_object(me, stra + "\n");
		return 1;
	}
	if (bs != "yes")
		return notify_fail("��ȡ���˼�����\n");
		
	if (!objectp(obj = present(id, me)))
		return notify_fail("������û������������\n");
	
	if (obj->query("jianding"))
		return notify_fail(obj->name() +NOR+ "�Ѿ��������ˣ�����Ҫ�ټ�����\n");
	
	if (!obj->query("ok_jianding"))
		return notify_fail(obj->name() +NOR+ "û���������ԣ�����Ҫ������\n");
	
	if (obj->query("spoil"))
		return notify_fail(obj->name() +NOR+ "�Ѿ��𻵣��޷�������\n");
	
	mun = obj->query("value") / 10;
	if (mun < 10)
		mun = 10;
	if (me->query("balance") < mun)
		return notify_fail(obj->name() +NOR+ "��Ҫ������"+(MONEY_D->money_str(mun))+"����Ǯׯ������\n");
	
	if (obj->query("weapon_prop")) {
		type = "weapon_prop";
		all_sx = weapon_sx;
	} else {
		type = "armor_prop";
		all_sx = armor_sx;
	}
	
	obj->unequip();
	if (sx = obj->query(type))
	{
		if (sizeof(sx) > 0) {
			list_sx = keys(sx);
			for(i=0;i<sizeof(list_sx);i++){
				if (sx[list_sx[i]] > 0 && all_sx[list_sx[i]])
				{
					//���ӵ�����Ϊ����ǰ����/5*����+1
					j = (sx[list_sx[i]]);
					j -= obj->query("exp/"+list_sx[i]);//��ȥǿ��������
					k = random(j / 5 * all_sx[list_sx[i]])+ 1;
					obj->add(type + "/" + list_sx[i], k);
					obj->add("jianding/" + list_sx[i], k);

					str += name_sx[list_sx[i]] +"+"+k+" ";
					k = j/(all_sx[list_sx[i]]);
				}
			}
			//if (wizardp(me)) 
			if (random(100) < 10) //	10/100���ʳ��ڶ�������
			{
				list_sx = keys(all_sx);
				i = random(sizeof(list_sx));
				sx_a = list_sx[i];
				kk = random(k / 5 * all_sx[sx_a])+ 1;
				obj->add(type+"/"+sx_a, kk);
				obj->add("jianding/" + sx_a, kk);
				str += name_sx[sx_a] +"+"+(kk)+"";
			} 
			if (random(100) < 5) //	5/100���ʳ�����������
			{
							
				list_sx = keys(all_sx);
				i = random(sizeof(list_sx));
				sx_a = list_sx[i];
				kk = random(k / 5 * all_sx[sx_a])+ 1;
				obj->add(type+"/"+sx_a, kk);
				obj->add("jianding/" + sx_a, kk);
				str += name_sx[sx_a] +"+"+(kk)+"";
				
			}
			if (!wizardp(me))
				me->add("balance", -mun);
			me->save();

			tell_object(me, sprintf("���������%s��\n"+name()+"�����㣺��������"+
								MONEY_D->money_str(mun)+"��"+(wizardp(me) ? HIR"��ʦ��ѡ�"NOR : "")+"\n", str));
		} else
			return notify_fail(obj->name() +NOR+ "����û���κ����ԣ��Ҽ������ˡ�\n");
	} else
		return notify_fail(obj->name() +NOR+ "����װ���ɣ��Ҽ������ˡ�\n");
	
	return 1;
}

int ask_jianding()
{
	int i;
	object ob;
	object me=this_player();
	object *obj;
	string str="", stra;
	int mun;
	
	obj = all_inventory(me);
	/*
	if (!wizardp(me))
		return 1;
	*/
	if (sizeof(obj) > 0) {
		stra = ZJOBLONG+sprintf("��ѡ����Ҫ������װ����\n");

		stra += ZJOBACTS2+ZJMENUF(2,2,10,30);
		for (i=0;i<sizeof(obj);i++) {
			if( !obj[i]->query("weapon_prop") && !obj[i]->query("armor_prop")) continue;//����Ϊװ��
			if( obj[i]->query("jianding", 1) || obj[i]->query("spoil", 1)) continue;//�������ĺ��𻵵Ĳ��ܼ���
			if( !obj[i]->query("ok_jianding", 1)) continue;//����Ϊ�ɼ���װ��
			
			mun = obj[i]->query("value") / 10;
			if (mun < 10)
				mun = 10;
			
			str += obj[i]->name() + NOR" ("+(MONEY_D->money_str(mun))+"):jianding_b " + file_name(obj[i]);
			if (i < sizeof(obj)-1)
				str += ZJSEP;
		}
		if (sizeof(str)>0) {
			stra +=str;
			tell_object(me, stra+"\n");
		} else
			tell_object(me, ZJOBLONG + "��������ʱû����Ҫ������װ����"NOR"\n");
	}
	
	return 1;
}
