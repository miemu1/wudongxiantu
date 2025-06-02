// fly.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

mapping city_name = ([
	"1":"���ֳ�",
	"2":"��Ұ��",
	"3":"�ŵ۳�",
	"4":"�����",
	"5":"������",
	"6":"���׳�",
	"7":"������",
	"8":"��ʥ��",
	"9":"��孳�",
	"1a":"���ִ�",
	"0":"����֮��",
	"a1":"һ�ſռ�",
	"a2":"���ſռ�",
	"a3":"���ſռ�",
	"a4":"�ĺſռ�",
	"a5":"��ſռ�",
	"a6":"���ſռ�",
	"a7":"�ߺſռ�",
	"a8":"�˺ſռ�",
	"a9":"�źſռ�",
	"FB":"ÿ�ո���",
	"fengmota":"��ħ��",
    "rocs":"����ռ�",
	"Aboss1":"��������",
	"Aboss2":"����֮��",
]);

mapping places = ([
	"yz" : "/d/city/guangchang",
	"yangzhou" : "/d/city/guangchang",

	"shenlong"       : "/d/shenlong/kongdi",
	"sld"       : "/d/shenlong/kongdi",
	
	"xnkj"       : "/data/hell/rocs/guangchang",
	
	"Aboss2"       : "/data/hell/11/guangchang",
	
    "Aboss1"       : "/data/hell/10/guangchang",

	"xbss"       : "/data/hell/0/guangchang",

    "FBA5"       : "/d/hangzhou/ningyuan",

    "FBA4"       : "/d/beijing/huangling",

    "FBA3"       : "/d/xiangyang/caodi3",

    "FBA2"       : "/d/guanwai/ningyuan",

    "FBA1"       : "/d/city/wuguan/qianting",

    "ykj9"       : "/data/hell/a9/guangchang",

    "ykj8"       : "/data/hell/a8/guangchang",

    "ykj7"       : "/data/hell/a7/guangchang",

    "ykj6"       : "/data/hell/a6/guangchang",

    "ykj5"       : "/data/hell/a5/guangchang",

    "ykj4"       : "/data/hell/a4/guangchang",
	
	"ykj3"       : "/data/hell/a3/guangchang",

	"ykj2"       : "/data/hell/a2/guangchang",

	"ykj1"       : "/data/hell/a1/guangchang",

	"zsrz0"       : "/d/huashan/shandian",

	"zsrz1"       : "/d/huashan/shandong",

	"zsrz2"       : "/d/dali/lushui",

	"zsrz3"       : "/d/xiakedao/zhuwu2",

	"zsrz4"       : "/d/beijing/shanlu3",

	"xinshouc"       : "/data/hell/1a/guangchang",

	"wulin1"       : "/data/hell/1/guangchang",
	"hell1"       : "/data/hell/1/guangchang",

	"wulin2"       : "/data/hell/2/guangchang",
	"hell2"       : "/data/hell/2/guangchang",

	"wulin3"       : "/data/hell/3/guangchang",
	"hell3"       : "/data/hell/3/guangchang",

	"wulin4"       : "/data/hell/4/guangchang",
	"hell4"       : "/data/hell/4/guangchang",

	"wulin5"       : "/data/hell/5/guangchang",
	"hell5"       : "/data/hell/5/guangchang",

	"wulin6"       : "/data/hell/6/guangchang",
	"hell6"       : "/data/hell/6/guangchang",

	"wulin7"       : "/data/hell/7/guangchang",
	"hell7"       : "/data/hell/7/guangchang",

	"wulin8"       : "/data/hell/8/guangchang",
	"hell8"       : "/data/hell/8/guangchang",

	"wulin9"       : "/data/hell/9/guangchang",
	"hell9"       : "/data/hell/9/guangchang",

	"hujia"  : "/d/guanwai/baihe",
	"hj"  : "/d/guanwai/baihe",
	"jiaofei" : "/d/city/ymzhengting",   //�˷�
	"wdt"  : "/d/fuben/wudaotai/wudaotai",    //�����
	"tiaozhao"  : "/data/hell/fengmota/entrance",    //��
	"gw"  : "/d/guanwai/jishi",
	"guanwai"  : "/d/guanwai/jishi",
	"fuben1"  : "/d/guanwai/ningyuan1",

	"bj"  : "/d/beijing/tiananmen",
	"beijing"  : "/d/beijing/tiananmen",

	"cd"  : "/d/city3/guangchang",
	"chengdu"  : "/d/city3/guangchang",

	"changan"  : "/d/changan/bridge2",
	"ca"  : "/d/changan/bridge2",
	"sanxiu":"/d/sanxiu/sanxiumen",

	"fz"   : "/d/fuzhou/dongjiekou",
	"fuzhou"   : "/d/fuzhou/dongjiekou",

	"foshan"   : "/d/foshan/street3",
	"fs"   : "/d/foshan/street3",

	"qz" : "/d/quanzhou/zhongxin",
	"quanzhou" : "/d/quanzhou/zhongxin",

	"jx"  : "/d/quanzhou/jiaxing",
	"jiaxing"  : "/d/quanzhou/jiaxing",

	"hz" : "/d/hangzhou/road10",
	"hangzhou" : "/d/hangzhou/road10",

	"sz"   : "/d/suzhou/canlangting",
	"suzhou"   : "/d/suzhou/canlangting",

	"hmy"  : "/d/heimuya/up1",
	"wugong"   : "/d/quanzhen/zhongxin",

	"ts"  : "/d/taishan/taishanjiao",
	"taishan"  : "/d/taishan/taishanjiao",

	"dl"     : "/d/dali/center",
	"dali"     : "/d/dali/center",

	"nanyang"  : "/d/shaolin/nanyang",
	"ny"  : "/d/shaolin/nanyang",

	"xy": "/d/xiangyang/guangchang",
	"xiangyang": "/d/xiangyang/guangchang",

	"yongdeng" : "/d/huanghe/yongdeng",
	"yd" : "/d/huanghe/yongdeng",

	"lingzhou" : "/d/lingzhou/center",
	"lz" : "/d/lingzhou/center",

	"henyang"  : "/d/henshan/hengyang",
	"hy"  : "/d/henshan/hengyang",

	"xx"  : "/d/xingxiu/xxh1",
	"xingxiu"  : "/d/xingxiu/xxh1",

	"bt"   : "/d/baituo/guangchang",       
	"baituo"   : "/d/baituo/guangchang",     

	"qzj" : "/d/quanzhen/damen",
	"quanzhen" : "/d/quanzhen/damen",

	"zhongnan" : "/d/quanzhen/shanjiao",
	"gm"     : "/d/gumu/mumen",
	"gumu"     : "/d/gumu/mumen",

	"mr"   : "/d/yanziwu/hupan",
	"murong"   : "/d/yanziwu/hupan",
	"yzw"  : "/d/yanziwu/bozhou",

	"lj"  : "/d/lingjiu/jian",
	"lingjiu"  : "/d/lingjiu/jian",

	"sl"  : "/d/shaolin/shanmen",
	"shaolin"  : "/d/shaolin/shanmen",

	"ruzhou"  : "/d/shaolin/ruzhou",
	"rz"  : "/d/shaolin/ruzhou",

	"wd"   : "/d/wudang/jiejianyan",
	"wudang"   : "/d/wudang/jiejianyan",

	"xyg"  : "/d/xiaoyao/xiaodao4",	
	"xiaoyao"  : "/d/xiaoyao/xiaodao4",	

	"hs"  : "/d/huashan/shaluo",
	"huashan"  : "/d/huashan/shaluo",
	"hsjz"  : "/d/huashan/pingdi",

	"xs"  : "/d/xuedao/nroad4",
	"xueshan"  : "/d/xuedao/nroad4",

	"xd"   : "/d/xuedao/wangyougu",
	"xuedao"   : "/d/xuedao/wangyougu",

	"kl"   : "/d/kunlun/klshanlu",
	"kunlun"   : "/d/kunlun/klshanlu",

	"em"     : "/d/emei/huayanding",
	"emei"     : "/d/emei/huayanding",
	"jinding"  : "/d/emei/jinding",

	"mj" : "/d/mingjiao/shanjiao",
	"mingjiao" : "/d/mingjiao/shanjiao",
	"nanhai"   : "/d/xiakedao/haibin",

	"guiyun"   : "/d/guiyun/taihu",

	"thd"  : "/d/taohua/tingzi",
	"taohua"  : "/d/taohua/tingzi",

	"moye"  : "/d/item/xiaowu",
	
	"yihua" : "/d/yihua/gudi",
	"tangmen" : "/d/tangmen/zhongxin",
	"mojiao" : "/d/wansong/damen",
	"shushan" : "/d/shushan/shanmen",
	"zhenyaota" : "/d/shushan/zhenyaota/tower",
	"baiyun" : "/d/baiyun/nandajie",
	"dazao" : "/d/npc/m_weapon/xuanbing1",
	"biwu1" : "/d/lunjian1/enter",
	"biwu2" : "/d/lunjian2/enter",
	"biwu3" : "/d/lunjian3/enter",
	"xuanminggu" : "/d/xuanminggu/xuanmingfeng",
	"huanhua"  : "/d/huanhua/podi",
    "jueqing"     : "/d/jueqing/shanjiao",
]);

int main(object me, string arg)
{
	object flying, room;
	string msg,where,*citys,dir;
	int i;

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

	if (me->query_temp("is_flying")) 
		return notify_fail("���������ڷ����У�\n");
		
	if (! environment(me)->query("outdoors")&& !wizardp(me) ) 
		return notify_fail("�ڷ����ﲻ�����ܣ�\n");
	
	if (! me->query("born"))
       return notify_fail("�㻹û�г����أ�\n");
		
	if (environment(me)->query("no_magic") || environment(me)->query("no_fly"))
		return notify_fail("�㷢�������е�Ź֣���������������ָ�ӣ�\n");
		
		if (me->is_ghost()) 
		return notify_fail("���㻹������˵�ɡ�\n"); 
	
	if (environment(me)->query("fuben2"))
		return notify_fail("���ڸ����ڲ���ʹ�ø�ָ�\n");							

	if (arg == "home" && ! me->query("private_room/position")) 
		return notify_fail("�㻹û��ס���أ�\n");

	if (arg == "home" && stringp(me->query("private_room/position")) && file_size(me->query("private_room/position") + ".c") > 0)
		room = get_object(me->query("private_room/position"));
	else if(arg == "hell")
	{
		citys = list_dirs("/data/hell/");
		if (sizeof(citys)<1) {
			return notify_fail("Ŀǰ����֮���ǿճǣ�\n");
		}
		msg = ZJOBLONG"��ѡ����У�\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		for(i=0;i<sizeof(citys);i++)
		{
			msg += city_name[citys[i]]+":fly hell "+citys[i];
			if(i<(sizeof(citys)-1)) msg += ZJSEP;
		}
		write(msg+"\n");
		return 1;
	}
	else if(sscanf(arg,"hell %s",dir)==1)
	{
		//if(!wizardp(me))
		//	return notify_fail("�Ժ󿪷š�\n");
		if(file_size("/data/hell/"+dir)!=-2)
			return notify_fail("û��������С�\n");
		if(file_size("/data/hell/"+dir+"/guangchang.c")<0)
			return notify_fail("������ڴ�������ϵ����Ա��\n");
		room = get_object("/data/hell/"+dir+"/guangchang");
	}
	else
	{
		if (member_array(arg, keys(places)) == -1) 
			return notify_fail("����ط��޷���Ԧ����ȥ��\n");
		room = get_object(places[arg]);
	}
	if (! room) return notify_fail("��о����ƺ��Ǹ��ط��е㲻�Ծ���\n");
	

	where = room->query("short");
	//message_vision(HIM"$N�ʹ�һ�����ڣ��ӿ�������һֻ"HIW"�׵�"NOR+HIM"��"HIM"\n$NԾ�ϰ׵�ֱ��������"+where+""HIM"�����ȥ��"NOR"\n"NOR"\n", me);
	me->move("/d/city/kongzhong");

	me->set_temp("is_flying",1);

if( (string)me->query("feixing") == "����") {
            message_vision(HIM"$N�ʹ�һ�����ڣ��ӿ�������һֻ"HIW"�׵�"NOR+HIM"��"HIM"\n$NԾ�ϰ׵�ֱ��������"+where+""HIM"�����ȥ��"NOR"\n"NOR"\n", me);
              }
if( (string)me->query("feixing") == "��ӥ") {
            message_vision(HIM"$N�ʹ�һ�����ڣ��ӿ�������һֻ"HIW"��ӥ"NOR+HIM"��"HIM"\n��ӥץס��ļ��ֱ��������"+where+""HIM"�����ȥ��"NOR"\n"NOR"\n", me);
              }
if( (string)me->query("feixing") == "��ɽ��") {
             message_vision(HIC"$N������ھ����ӳ�һ�ѱ�����$N�ɳ۶��ϣ�һ�С��������С���"+where+""HIM"�����ȥ��������\n"NOR, me);
              }
	if (me->query("zjvip/times") >1) call_out("fly_fin",1,where,flying,me,room);
        else call_out("fly_fin",3,where,flying,me,room);
	return 1;
}
void fly_fin(string where,object flying,object me,object room)
{
	if (!me)
		return;
	me->move(room);
  if( (string)me->query("feixing")=="��ɽ��") {
	     message_vision(HIC"\nһ����������,$N""�ӽ������������� \n"
NOR, me);
	}
	if( (string)me->query("feixing")=="����") {
	  tell_room(environment(me),HIC""+me->name()+"����"HIW"�׵�"HIC"��Զ���ɳ۶������������¡�"NOR"\n",me);
	}
	if( (string)me->query("feixing")=="��ӥ") {
	  tell_room(environment(me),HIC""+me->name()+"��"HIW"��ӥ"HIC"�����϶�������"NOR"\n",me);
	}
	//tell_object(me, HIC"��һ·�����׵���У����ڸϵ���" + where + ""HIC"��"NOR"\n"NOR"\n");
        tell_room(environment(me),HIC""+me->name()+"����"HIW"�׵�"HIC"��Զ���ɳ۶������������¡�"NOR"\n",me);
	me->delete_temp("is_flying");

}
int help(object me)
{
	write(@HELP
ָ���ʽ : fly <�ص�>
�����׵�˲��ɵ�ĳ���ص㡣Ŀǰ����ȥ�ĵط��У�
----------------------------------------------------------------------
yangzhou : ��  ��	beijing : ��  ��	chengdu : ��  ��
changan : ��  ��	hangzhou : ��  ��	suzhou : ��  ��
xiangyang: ��  ��	fuzhou : ��  ��	  foshan : ��  ɽ
lingzhou : ��  ��	henyang  : ��  ��	jiaxing : ��  ��	
quanzhou : Ȫ  ��	dali  : ��  ��	wudang : �䵱ɽ
taishan : ̩  ɽ	quanzhen : ȫ���	emei : ��üɽ	
mingjiao : ������	xingxiu : ���޺�	gumu : ��  Ĺ	
huashan : ��  ɽ	murong  : Ľ  ��	xueshan : ѩ  ɽ
xuedao   : ѩ����	xiaoyao  : ��ң��	lingjiu : ���չ�	
guanwai  : ��  ��	guiyun   : ����ׯ	nanhai   : ��  ��
wugong   : �书��	zhongnan : ����ɽ	yzw  : ������	
hmy  : ��ľ��	nanyang  : ��  ��	kl   : ����ɽ
sl  : ������	bt   : ����ɽ	home  : ס  ��
thd     : �һ���  hsjz  : ��ɽ����     yihua  : �ƻ���
----------------------------------------------------------------------
HELP
	);

	return 1;
}
 
