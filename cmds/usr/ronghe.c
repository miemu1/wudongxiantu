// 兵器融合-夫子

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj,target,*obs;
	int i,num,need;
	string item;
	mapping *needs;

	if (!arg)
		return notify_fail("你要融合什么兵器？\n");



	if(sscanf(arg,"%s %d",item,num)!=2)
	{
		if (!objectp(obj=present(arg,me)))
			return notify_fail("你要融合什么兵器？\n");

		

		if(obj->query("ronghe/be")&&arrayp(needs=obj->query("ronghe/need")))
		{
			obs = ({});
                                                target = new(obj->query("ronghe/be"));
			for(i=0;i<sizeof(needs);i++)
			{
				if(!objectp(present(needs[i]["id"],me)))
					return notify_fail(HIW"你身上缺少"HIR"【"+needs[i]["name"]+"】，"HIW"不能融合成"HIY"["+target->query("name")+"]。\n"NOR);
				obs += ({ present(needs[i]["id"],me) });
			}
			target = new(obj->query("ronghe/be"));
			target->move(me);
	write(HIR"恭喜：你获得了一个"+target->query("name")+"。\n"NOR);
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"获得了一个"+target->query("name")+"！");
			for(i=0;i<sizeof(obs);i++)
			{destruct (obs[i]);}
			
		
			

			return 1;
		}

		if(!obj->query("ronghe/be")||!(need=obj->query("ronghe/need"))||!obj->query_amount())
			return notify_fail(obj->query("name")+"不能融合生成高级兵器！\n");

		return 1;
	}

	if (!objectp(obj=present(item,me)))
		return notify_fail("你要融合什么兵器？\n");


	return 1;
}

