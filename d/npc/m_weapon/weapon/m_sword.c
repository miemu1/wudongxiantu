// m_sword.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
inherit S_WEAPON;

int duanlian(object weapon);
int do_hui(object weapon);


string query_autoload() { return 1 + ""; }	//autoload weapon

void init()
{
	add_action("do_duanlian","duanlian");
	add_action("do_hui","hui");
}


void create()
{
	object me;
	string w_name,w_id,w_or,p_name,name;
	int w_lv,dj,color;
	me = this_player();
//读入数据
//自制武器被他人得到后有bug，加入以下语句可以解决。
/*        if (!(me->query("weapon/name")))
{
                remove_call_out("destrory");
                call_out("destrory",1,me);
                return;
}*/
	w_name=me->query("weapon/name");
	w_id = "my "+me->query("weapon/id");
	w_or = me->query("weapon/or");
	w_lv = me->query("weapon/lv");
	dj = me->query("weapon/dj");
        color = w_lv / 2;

	p_name = HIY"凡品"NOR;

	if (me->query("weapon/pin"))
	{
		p_name = me->query("weapon/pin");
	}
        switch(color){
                case 1:
                        name = WHT + p_name + w_name + NOR;
                        break;
                case 2:
                        name = HIR + p_name + w_name + NOR;
                        break;
                case 3:
                case 4:
                        name = HIB + p_name + w_name + NOR;
                        break;
                case 5:
                        name = HIY + p_name + w_name + NOR;
                        break;
                case 6:
                        name = HIM + p_name + w_name + NOR;
                        break;
                case 7:
                        name = MAG + p_name + w_name + NOR;
                        break;
                case 8:
                        name = HIW + p_name + w_name + NOR;
                        break;
                case 9:
                        name = HIC + p_name + w_name + NOR;
                        break;
                default:
                        name = HIG + p_name + w_name + NOR;
                        break;
        }
	if (!me->query("weapon/name"))
	{
		w_name="自制的长剑";
	}
	if (!me->query("weapon/id"))
	{
		w_id="sword";
	}
	if (!me->query("weapon/or"))
	{
		w_or="千年神木";
	}
	if (!me->query("weapon/lv"))
	{
		w_lv=5;
	}
	if (!me->query("weapon/dj"))
	{
		dj=1;
	}
	/*if (me->query("weapon/lv",1) > 150)
	{
		w_lv=150;
	}*/

	set_name(name , ({w_id}));
	set("unit", "口");
	set("weapon_prop/baoji", w_lv * 2);
	set("weapon_prop/yuanshen", me->query("yuanshen/weapon"));
	set("pin",me->query("weapon/pin"));
	set("value",1000);
	set("ownmake",1);
	set("no_sell",1);
	set("no_give",1);
	set("no_get",1);

	set("no_drop",1);
	set("no_get",1);

	set("no_put",1);
	set_desc(w_lv,w_or,w_name);
	switch(w_or)
		{
		case "千年神木" :
			set_weight(500);
			set("material", "iron");
			break;
		case "海底金母" :
			set_weight(1000);
			set("material", "steel");
			break;
		case "寒丝羽竹" :
			set_weight(30);
			set("material", "bamboo");
			break;
		default :
		}
	if( me->query("weapon/wield_msg"))
		set("wield_msg", me->query("weapon/wield_msg")+"\n");
	else
		set("wield_msg", "$N往腰中一带，抽出了一口"+name+"握在手中。\n");
	if( me->query("weapon/unwield_msg"))
		set("unwield_msg", me->query("weapon/unwield_msg")+"\n");
	else
		set("unwield_msg", "$N手中"+name+"迎风一抖，眨眼间已然不见影踪。\n");
	if (!me->query("weapon/pin"))
		init_sword(w_lv * 10 *dj);
	else if (me->query("weapon/pin") == "中品")
		init_sword(w_lv * 15 *dj);
	else if (me->query("weapon/pin") == "上品")
		init_sword(w_lv * 18 *dj);
	else if (me->query("weapon/pin") == "神器")
		init_sword(w_lv * 21 *dj);
	else if (me->query("weapon/pin") == "天器")
		init_sword(w_lv * 22 *dj);
	else if (me->query("weapon/pin") == "地器")
		init_sword(w_lv * 23 *dj);	
	else if (me->query("weapon/pin") == "玄器")
		init_sword(w_lv * 24 *dj);
	else if (me->query("weapon/pin") == "灵器")
		init_sword(w_lv * 25 *dj);
	else if (me->query("weapon/pin") == "冥器")
		init_sword(w_lv * 26 *dj);
	else if (me->query("weapon/pin") == "圣器")
		init_sword(w_lv * 27 *dj);
	else if (me->query("weapon/pin") == "宝器")
		init_sword(w_lv * 28 *dj);		
	else if (me->query("weapon/pin") == "魔器")
		init_sword(w_lv * 29 *dj);		
	else if (me->query("weapon/pin") == "仙器")
		init_sword(w_lv * 30 *dj);		
	else if (me->query("weapon/pin") == "胸器")
		init_sword(w_lv * 31 *dj);		
	else if (me->query("weapon/pin") == "一阶鬼器")
		init_sword(w_lv * 32 *dj);			
else if (me->query("weapon/pin") == "二阶鬼器")
		init_sword(w_lv * 33 *dj);			
else if (me->query("weapon/pin") == "三阶鬼器")
		init_sword(w_lv * 34 *dj);			
else if (me->query("weapon/pin") == "四阶鬼器")
		init_sword(w_lv * 35 *dj);			
else if (me->query("weapon/pin") == "五阶鬼器")
		init_sword(w_lv * 36 *dj);		
else if (me->query("weapon/pin") == "一阶葬器")
		init_sword(w_lv * 37 *dj);	
else if (me->query("weapon/pin") == "二阶葬器")
		init_sword(w_lv * 38 *dj);	
else if (me->query("weapon/pin") == "三阶葬器")
		init_sword(w_lv * 39 *dj);	
else if (me->query("weapon/pin") == "四阶葬器")
		init_sword(w_lv * 40 *dj);	
else if (me->query("weapon/pin") == "五阶葬器")
		init_sword(w_lv * 41 *dj);		
else if (me->query("weapon/pin") == "六阶葬器")
		init_sword(w_lv * 42 *dj);		
else if (me->query("weapon/pin") == "七阶葬器")
		init_sword(w_lv * 43 *dj);	
else if (me->query("weapon/pin") == "八阶葬器")
		init_sword(w_lv * 44 *dj);	
else if (me->query("weapon/pin") == "九阶葬器")
		init_sword(w_lv * 45 *dj);	
else if (me->query("weapon/pin") == "十阶葬器")
		init_sword(w_lv * 46 *dj);		
else if (me->query("weapon/pin") == "一阶荒器")
		init_sword(w_lv * 47 *dj);			
else if (me->query("weapon/pin") == "二阶荒器")
		init_sword(w_lv * 48 *dj);			
else if (me->query("weapon/pin") == "三阶荒器")
		init_sword(w_lv * 49 *dj);			
else if (me->query("weapon/pin") == "四阶荒器")
		init_sword(w_lv * 50 *dj);			
else if (me->query("weapon/pin") == "五阶荒器")
		init_sword(w_lv * 51 *dj);			
else if (me->query("weapon/pin") == "六阶荒器")
		init_sword(w_lv * 52 *dj);			
else if (me->query("weapon/pin") == "七阶荒器")
		init_sword(w_lv * 53 *dj);			
else if (me->query("weapon/pin") == "八阶荒器")
		init_sword(w_lv * 54 *dj);		
else if (me->query("weapon/pin") == "九阶荒器")
		init_sword(w_lv * 55 *dj);		
else if (me->query("weapon/pin") == "十阶荒器")
		init_sword(w_lv * 56 *dj);			
else if (me->query("weapon/pin") == "昊天一阶")
		init_sword(w_lv * 57 *dj);				
else if (me->query("weapon/pin") == "昊天二阶")
		init_sword(w_lv * 58 *dj);					
else if (me->query("weapon/pin") == "昊天三阶")
		init_sword(w_lv * 59 *dj);					
else if (me->query("weapon/pin") == "昊天四阶")
		init_sword(w_lv * 60 *dj);					
else if (me->query("weapon/pin") == "昊天五阶")
		init_sword(w_lv * 61 *dj);					
else if (me->query("weapon/pin") == "昊天六阶")
		init_sword(w_lv * 62 *dj);				
else if (me->query("weapon/pin") == "昊天七阶")
		init_sword(w_lv * 63 *dj);				
else if (me->query("weapon/pin") == "昊天八阶")
		init_sword(w_lv * 64 *dj);				
else if (me->query("weapon/pin") == "昊天九阶")
		init_sword(w_lv * 65 *dj);					
else if (me->query("weapon/pin") == "昊天十阶")
		init_sword(w_lv * 66 *dj);					
else if (me->query("weapon/pin") == "錾金一阶")
		init_sword(w_lv * 67 *dj);					
else if (me->query("weapon/pin") == "錾金二阶")
		init_sword(w_lv * 68 *dj);					
else if (me->query("weapon/pin") == "錾金三阶")
		init_sword(w_lv * 69 *dj);					
else if (me->query("weapon/pin") == "錾金四阶")
		init_sword(w_lv * 70 *dj);					
else if (me->query("weapon/pin") == "錾金五阶")
		init_sword(w_lv * 71 *dj);					
else if (me->query("weapon/pin") == "錾金六阶")
		init_sword(w_lv * 72 *dj);					
else if (me->query("weapon/pin") == "錾金七阶")
		init_sword(w_lv * 73 *dj);					
else if (me->query("weapon/pin") == "錾金八阶")
		init_sword(w_lv * 74 *dj);					
else if (me->query("weapon/pin") == "錾金九阶")
		init_sword(w_lv * 75 *dj);					
else if (me->query("weapon/pin") == "錾金十阶")
		init_sword(w_lv * 76 *dj);					
else if (me->query("weapon/pin") == "孤星一阶")
		init_sword(w_lv * 77 *dj);					
else if (me->query("weapon/pin") == "孤星二阶")
		init_sword(w_lv * 78 *dj);					
else if (me->query("weapon/pin") == "孤星三阶")
		init_sword(w_lv * 79 *dj);					
else if (me->query("weapon/pin") == "孤星四阶")
		init_sword(w_lv * 80 *dj);					
else if (me->query("weapon/pin") == "孤星五阶")
		init_sword(w_lv * 81 *dj);					
else if (me->query("weapon/pin") == "孤星六阶")
		init_sword(w_lv * 82 *dj);					
else if (me->query("weapon/pin") == "孤星七阶")
		init_sword(w_lv * 83 *dj);					
else if (me->query("weapon/pin") == "孤星八阶")
		init_sword(w_lv * 84 *dj);					
else if (me->query("weapon/pin") == "孤星九阶")
		init_sword(w_lv * 85 *dj);					
else if (me->query("weapon/pin") == "孤星十阶")
		init_sword(w_lv * 86 *dj);					
else if (me->query("weapon/pin") == "孤星十一阶")
		init_sword(w_lv * 87 *dj);					
else if (me->query("weapon/pin") == "孤星十二阶")
		init_sword(w_lv * 88 *dj);					
else if (me->query("weapon/pin") == "孤星十三阶")
		init_sword(w_lv * 89 *dj);					
else if (me->query("weapon/pin") == "孤星十四阶")
		init_sword(w_lv * 90 *dj);					
else if (me->query("weapon/pin") == "孤星十五阶")
		init_sword(w_lv * 91 *dj);					
else if (me->query("weapon/pin") == "孤星十六阶")
		init_sword(w_lv * 92 *dj);					
else if (me->query("weapon/pin") == "孤星十七阶")
		init_sword(w_lv * 93 *dj);					
else if (me->query("weapon/pin") == "孤星十八阶")
		init_sword(w_lv * 94 *dj);					
else if (me->query("weapon/pin") == "孤星十九阶")
		init_sword(w_lv * 95 *dj);					
else if (me->query("weapon/pin") == "孤星二十阶")
		init_sword(w_lv * 96 *dj);					
else if (me->query("weapon/pin") == "孤星二十一阶")
		init_sword(w_lv * 97 *dj);					
else if (me->query("weapon/pin") == "孤星二十二阶")
		init_sword(w_lv * 98 *dj);					
else if (me->query("weapon/pin") == "孤星二十三阶")
		init_sword(w_lv * 99 *dj);					
else if (me->query("weapon/pin") == "孤星二十四阶")
		init_sword(w_lv * 100 *dj);					
else if (me->query("weapon/pin") == "孤星二十五阶")
		init_sword(w_lv * 101 *dj);					
else if (me->query("weapon/pin") == "孤星二十六阶")
		init_sword(w_lv * 102 *dj);					
else if (me->query("weapon/pin") == "孤星二十七阶")
		init_sword(w_lv * 103 *dj);					
else if (me->query("weapon/pin") == "孤星二十八阶")
		init_sword(w_lv * 104 *dj);					
			

	
	setup();
}



int do_duanlian(object weapon,object me)
{
	object obj;
	int w_zhi, w_level;
	string w_or;
	string arg;
		me=this_player();

obj=present("xueye", me);//渡渡加入锻造兵器系统

	if( !weapon )
		return notify_fail("你要锻炼什么?\n");

	if (me->is_fighting())
		return notify_fail("你打着呢?\n");

	if (me->is_busy())
		return notify_fail("你忙着呢?\n");

	if( (int)me->query("max_neili") < 10 )
		return notify_fail("你的内力不够，无法锻炼剑气！\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力不够，无法锻炼兵器！\n");

	if (userp(me) && !me->query_skill_mapped("force"))
		return notify_fail("你没有内功，在使用中啊!\n");
		
	if(!present("xueye", me))
		return notify_fail("你的身上没有树精之血或者数量不足不足5！\n");
		
	if(!present("xueye", me)&& obj->query_amount()<5)
		return notify_fail("你的身上没有树精之血或者数量不足5！\n");
		
	if ( obj->query_amount()<5)
		return notify_fail("你的身上没有树精之血或者数量不足5！\n");
		
	if( me->query_skill("shenzhao-jing", 1) > 100
            && (int)me->query("max_neili") < 5000 )
		return notify_fail("你的内力不够，无法锻炼兵器！\n");

	if( (int)me->query("qi") < 150 )
		return notify_fail("你的气不够，无法锻炼剑气！\n");

	if( (int)me->query("eff_qi") < 30 )
		return notify_fail("你现在的体力太弱，无法锻炼剑气！\n");

	if( (int)me->query("eff_jing") < 10 )
		return notify_fail("你现在的精力无法集中，不能锻炼剑气！\n");


	message_vision(HIR "$N左手直指剑脊，右手手握树精血液将其一丝丝的传了进去。\n" NOR, me);

	me->add("qi",-150);
	me->add("eff_qi",-30);
	me->add("jing",-30);
	me->add("eff_jing",-30);
	me->add("weapon_max",5);
	me->add("weapon/lv",5);
		obj->add_amount(-5);

		message_vision(HIY "剑身忽的一亮，一道金光隐入$N的剑体，不见了！\n" NOR,me);
		message_vision(HIG "$N的剑的等级提高了！\n" NOR, me);
	message_vision(HIC "$N的剑气提升了!\n" NOR, me);
		message("vision",ZJCHANNEL+ HIC"炼"HIM"器"HIW"："HIC""+me->query("name")+"("+me->query("id")+")将树精之血导入武器之中，武器等级得到提升！\n" NOR, users());		

	return 1;
}


int do_hui(object weapon)
{
	string w_name;
	object me,ob;
	me=this_player();
	w_name=me->query("weapon/name");
	if( !weapon )
		return notify_fail("你要摧毁什么?\n");
	message_vision(HIR "$N大喝一声，一掌擎剑，一掌猛力击下。结果轰隆一声巨响"
			+w_name+HIR"断为两截!\n" NOR,me);
	me->set("weapon/make",0);
	destruct( this_object() );
	me->delete("weapon");

	me->save();

	return 1;
}
/*void owner_is_killed()
{
        write(HIY"只见一声清脆的响声，"+query("name")+HIY"落在地上，断成数截。\n"NOR);
        this_object()->unequip();
        this_object()->reset_action();
        this_object()->set("name", query("name") + "的碎片");
        this_object()->set("value", 0);
        this_object()->set("weapon_prop", 0);
}*/
