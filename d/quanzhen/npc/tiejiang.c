// by ranger_游侠
// Smith.c

inherit NPC;
inherit F_DEALER;
int ask_jianding();

//后面数字为倍数
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
	"attack" : "命中",
	"damage" : "伤害",
	"neili" : "内力",
	"dodge" : "躲闪",
	"parry" : "招架",
	"armor" : "防御",
	"qi" : "气血",
	"jing" : "精神",
]);

void create()
{
	set_name("奇怪的铁匠",({"tie jiang","smith"}));
	set("gender","男性");
	set("per",18);
	set("age",33);
	set("long","铁匠正用铁钳夹住一块红热的铁块放进炉中。");
	set("combat_exp",100);
	set("vendor_goods", ({
		"/clone/cloth/pi",
		"/clone/weapon/sword/biyusword",
		"/clone/weapon/blade/zijinblade", 
		"/clone/weapon/unarmed/zhizhua"
	}) );
	setup();
	set("inquiry", ([
		"鉴定装备" : (: ask_jianding :),
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
			return notify_fail("你身上没有这样东西。\n");
		
		stra = ZJOBLONG+sprintf("确定需要鉴定"+obj->name()+NOR"吗？\n");

		stra += ZJOBACTS2+ZJMENUF(2,2,10,30);
		stra += HIG+"确认鉴定"NOR":jianding_b " + file_name(obj) +" yes"+ZJSEP;
		stra += HIW+"取消鉴定"NOR":jianding_b " + file_name(obj) +" no";
		tell_object(me, stra + "\n");
		return 1;
	}
	if (bs != "yes")
		return notify_fail("你取消了鉴定。\n");
		
	if (!objectp(obj = present(id, me)))
		return notify_fail("你身上没有这样东西。\n");
	
	if (obj->query("jianding"))
		return notify_fail(obj->name() +NOR+ "已经鉴定过了，不需要再鉴定。\n");
	
	if (!obj->query("ok_jianding"))
		return notify_fail(obj->name() +NOR+ "没有特殊属性，不需要鉴定。\n");
	
	if (obj->query("spoil"))
		return notify_fail(obj->name() +NOR+ "已经损坏，无法鉴定。\n");
	
	mun = obj->query("value") / 10;
	if (mun < 10)
		mun = 10;
	if (me->query("balance") < mun)
		return notify_fail(obj->name() +NOR+ "需要鉴定费"+(MONEY_D->money_str(mun))+"，你钱庄存款不够。\n");
	
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
					//增加的属性为：当前属性/5*倍数+1
					j = (sx[list_sx[i]]);
					j -= obj->query("exp/"+list_sx[i]);//减去强化的属性
					k = random(j / 5 * all_sx[list_sx[i]])+ 1;
					obj->add(type + "/" + list_sx[i], k);
					obj->add("jianding/" + list_sx[i], k);

					str += name_sx[list_sx[i]] +"+"+k+" ";
					k = j/(all_sx[list_sx[i]]);
				}
			}
			//if (wizardp(me)) 
			if (random(100) < 10) //	10/100几率出第二条属性
			{
				list_sx = keys(all_sx);
				i = random(sizeof(list_sx));
				sx_a = list_sx[i];
				kk = random(k / 5 * all_sx[sx_a])+ 1;
				obj->add(type+"/"+sx_a, kk);
				obj->add("jianding/" + sx_a, kk);
				str += name_sx[sx_a] +"+"+(kk)+"";
			} 
			if (random(100) < 5) //	5/100几率出第三条属性
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

			tell_object(me, sprintf("鉴定结果：%s。\n"+name()+"告诉你：共花费了"+
								MONEY_D->money_str(mun)+"。"+(wizardp(me) ? HIR"巫师免费。"NOR : "")+"\n", str));
		} else
			return notify_fail(obj->name() +NOR+ "根本没有任何属性，我鉴定不了。\n");
	} else
		return notify_fail(obj->name() +NOR+ "不是装备吧？我鉴定不了。\n");
	
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
		stra = ZJOBLONG+sprintf("请选择需要鉴定的装备：\n");

		stra += ZJOBACTS2+ZJMENUF(2,2,10,30);
		for (i=0;i<sizeof(obj);i++) {
			if( !obj[i]->query("weapon_prop") && !obj[i]->query("armor_prop")) continue;//必须为装备
			if( obj[i]->query("jianding", 1) || obj[i]->query("spoil", 1)) continue;//鉴定过的和损坏的不能鉴定
			if( !obj[i]->query("ok_jianding", 1)) continue;//必须为可鉴定装备
			
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
			tell_object(me, ZJOBLONG + "你身上暂时没有需要鉴定的装备。"NOR"\n");
	}
	
	return 1;
}
