// rideto.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

mapping places = ([
	"yangzhou" : "/d/city/guangchang",
	"gc"       : "/d/city/guangchang",
	"beijing"  : "/d/beijing/tiananmen",
	"chengdu"  : "/d/city3/guangchang",
	"changan"  : "/d/changan/bridge2",
	"suzhou"   : "/d/suzhou/canlangting",
	"hangzhou" : "/d/hangzhou/road10",
	"fuzhou"   : "/d/fuzhou/dongjiekou",
	"foshan"   : "/d/foshan/street3",
	"guiyun"   : "/d/guiyun/taihu",
	"heimuya"  : "/d/heimuya/up1",
//	"kunming"  : "/d/kunming/jinrilou",
//	"lanzhou"  : "/d/lanzhou/guangchang",
//	"kaifeng"  : "/d/kaifeng/zhuque",
	"wugong"   : "/d/quanzhen/zhongxin",
	"taishan"  : "/d/taishan/taishanjiao",
	"dali"     : "/d/dali/center",
	"nanyang"  : "/d/shaolin/nanyang",
	"quanzhou" : "/d/quanzhou/zhongxin",
	"jiaxing"  : "/d/quanzhou/jiaxing",
	"xiangyang": "/d/xiangyang/guangchang",
	"yongdeng" : "/d/huanghe/yongdeng",
	"lingzhou" : "/d/lingzhou/center",
 //       "jingzhou" : "/d/jingzhou/guangchang",
 //       "zhongzhou": "/d/zhongzhou/shizhongxin",
	"henyang"  : "/d/henshan/hengyang",
	"guanwai"  : "/d/guanwai/jishi",
	"xingxiu"  : "/d/xingxiu/xxh1",
	"baituo"   : "/d/baituo/guangchang",       
	"quanzhen" : "/d/quanzhen/damen",
	"zhongnan" : "/d/quanzhen/shanjiao",
	"gumu"     : "/d/gumu/mumen",
 //       "luoyang"  : "/d/luoyang/center",
	"murong"   : "/d/yanziwu/hupan",
	"lingjiu"  : "/d/lingjiu/jian",
	"shaolin"  : "/d/shaolin/shanmen",
	"wudang"   : "/d/wudang/jiejianyan",
	"xiaoyao"  : "/d/xiaoyao/xiaodao4",	
	"huashan"  : "/d/huashan/shaluo",
	"xueshan"  : "/d/xuedao/nroad4",
	"xuedao"   : "/d/xuedao/wangyougu",
 //       "kunlun"   : "/d/kunlun/klshanlu",
	"emei"     : "/d/emei/huayanding",
	"mingjiao" : "/d/mingjiao/shanjiao",
	"nanhai"   : "/d/xiakedao/haibin",
	// "taohua"   : "/d/taohua/jingshe",
	"hujia"    : "/d/guanwai/xiaoyuan",
	"yanziwu"  : "/d/yanziwu/bozhou",
]);

int main(object me, string arg)
{
	object riding, room;
	string where;

	if (! arg) return help(me);

	if (me->over_encumbranced()) 
		return notify_fail("��ĸ��ɹ��أ��������á�\n"); 
	
	if (me->query_encumbrance() < 0) 
		return notify_fail("��ĸ��ɳ��ֹ��ϣ��������á�\n"); 

	if (me->query_temp("sleeped")) 
		return notify_fail("�������������ء�\n");

	if (me->is_in_prison())   
		return notify_fail("�����������أ������ʲô����\n");
				
	if (me->is_fighting()) 
		return notify_fail("����������ս����\n");

	if (me->is_busy() || me->query("doing")) 
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
		
	if (! objectp(riding = me->query_temp("is_riding")))
		return notify_fail("�㻹û�����\n"); 
	
	if (! present(riding->query("id"), me))
		return notify_fail("������ﲻ������ߣ�\n");

	/*
	if (present("letter", me)) 
		return notify_fail("�����ϴ����ܺ���\n");
	*/
		
	if (! environment(me)->query("outdoors")) 
		return notify_fail("�ڷ����ﲻ�����ܣ�\n");
		
	if (environment(me)->query("no_magic") || environment(me)->query("no_fly"))
		return notify_fail("�㷢�������е�Ź֣����������������ָ�ӣ�\n");		

	if (member_array(arg, keys(places)) == -1 && arg != "home") 
		return notify_fail("����ط��޷�������ȥ��\n");
		
	if (arg == "home" && ! me->query("private_room/position")) 
		return notify_fail("�㻹û��ס���أ�\n");

	if (arg == "home" && stringp(me->query("private_room/position")) &&
	    file_size(me->query("private_room/position") + ".c") > 0)
		room = get_object(me->query("private_room/position"));
	else
	room = get_object(places[arg]);
	if (! room) return notify_fail("��о����ƺ��Ǹ��ط��е㲻�Ծ���\n");
	
	message("vision", me->name() + "���š�" + riding->name() + NOR "���Ҵ�ææ���뿪�ˡ�\n",
		environment(me), ({me}));
	
	where = room->query("short");
	
	tell_object(me, "��һ·��ͣ�㣬���ڸϵ���" + where + "��\n");
	me->move(room);

	message("vision", me->name() + "���š�" + riding->name() + NOR "��һ·���۶�����\n",
		environment(me), ({me}));

	// me->receive_damage("qi", 10);

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : rideto <�ص�>
----------------------------------------------------------------------
�������ﵽ��ĳ���ص㡣Ŀǰ������������ȥ�ĵط��У�
yangzhou : ��  ��	beijing  : ��  ��	chengdu  : ��  ��
changan  : ��  ��	hangzhou : ��  ��	suzhou   : ��  ��
xiangyang: ��  ��	fuzhou   : ��  ��	foshan   : ��  ɽ
lingzhou : ��  ��	henyang  : ��  ��	jiaxing  : ��  ��	
quanzhou : Ȫ  ��	dali     : ��  ��	wudang   : �䵱ɽ
taishan  : ̩  ɽ	quanzhen : ȫ���	emei     : ��üɽ	
mingjiao : ������	xingxiu  : ���޺�	gumu     : ��  Ĺ	
huashan  : ��  ɽ	murong   : Ľ  ��	xueshan  : ѩ  ɽ
xuedao   : ѩ����	xiaoyao  : ��ң��	lingjiu  : ���չ�	
guanwai  : ��  ��	guiyun   : ����ׯ	nanhai   : ��  ��
wugong   : �书��	zhongnan : ����ɽ	yanziwu  : ������	
heimuya  : ��ľ��	nanyang  : ��  ��	home     : ס  ��
----------------------------------------------------------------------
HELP
	);

	return 1;
}
 

