// Room: /city/qianzhuang.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。帐台上有一个牌子(paizi)。
LONG
	);
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
        set("item_desc", ([
                "paizi": @TEXT
这里是钱庄，目前我们提供的服务有：
convert(huan)     兑换钱币。
deposit(cun)      存钱。
withdraw(qu)      取钱。
check(cha)        查询存款。
zhuanrock          转灵石给另一个玩家。
每次取钱必需缴纳百分之一的手续费，敝庄会从你的存款中扣取。
TEXT
        ]) );
	setup();
}

//是镜像
int is_mirror() { return 1; }