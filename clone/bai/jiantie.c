/* 融合兵器制作步骤
1. 打开融合兵器需要的物品文件 找到英文id
2. 加入并更改--见长剑文件-加入并更改部分 
*/

#include <weapon.h>
inherit SWORD;


void create()
{
	set_name("长剑aaaaa", ({ "jian1" }));                           //文件的英文id
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
	      set("icon","05035");
		set("long", "这是一柄普通的精钢剑，一般的剑客都配带此剑。\n");
		set("value", 200);
		set("material", "steel");

//------------------------------------------------------------------------------------------------------
//加入并更改部分
                                set("ronghe/be", __DIR__"jian");                 //融合后得到物品文件目录 = 融合目标
                                set("ronghe/need", ({                                  //融合所需物品的id 和名字 = 融合材料
			(["id":"jian1 2","name":"长剑"]), 
                                                (["id":"jian1","name":"长剑"]),
                                                             }));
/*
操作步骤
1.打开融合兵器需要的物品文件 找到英文id
2.更改融合目标的目录
3.将融合材料的id 替换成你找到材料的英文id，名字替换

例如打开屠龙刀文件   2把屠龙刀 融合成 倚天剑
                               set_name("屠龙刀", ({ "tulong dao" }));           //打开文件找到英文id
                                
                                set("ronghe/be", "/clone/weapon/yitian jian"); //融合成倚天剑 的目录
                                set("ronghe/need", ({                                       //改成屠龙刀的id和名字 那个数字2不要动！
			(["id":"tulong dao 2","name":"屠龙刀"]), 
                                                (["id":"tulong dao","name":"屠龙刀"]),
                                                             }));


*/

//-------------------------------------------------------------------------------------------------------


		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(25);
	setup();
}
