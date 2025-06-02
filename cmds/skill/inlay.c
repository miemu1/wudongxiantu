// enchase.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string msg, item, tessera;
	object *baoshi,obj, dest;
	int i,place;


	if (! arg)
		return notify_fail("��Ҫ��ʲô��������Ƕ��Ʒ��\n");

	if (me->is_busy())
		return notify_fail("��æ����������������������ɣ�\n");

	if (me->is_fighting())
		return notify_fail("���������ڴ�ܣ�ûʱ������Щ���顣\n");
		
if (sscanf(arg, "%s with %s set %d", item, tessera,place)==3)
   {
	if (! objectp(obj = present(tessera, me)))
		return notify_fail("������û��������������������Ƕ��\n");
		
	if (! objectp(dest = present(item, me)))
		return notify_fail("������û���������ߡ�\n");
	
	if (dest->item_owner() != me->query("id"))
		return notify_fail("������������İ�...\n");
      
    if (me->query("max_neili")<200)
    return notify_fail("���������Ϊ��˱�������ô���ܰѱ�ʯ��Ƕ���������أ�\n");
    
		me->add("max_neili",-200);
		
	if (random(3)>=1)
	return notify_fail("���뽫"+obj->query("name")+"��Ƕ��"+dest->query("name")+"�������ܵ�ǿ���ų⣬ֻ�����ա�\n");
	
	write("��ϲ����Ƕ�ɹ���\n");
	
	return dest->inlay_gem(obj, place);	
	
	}
	
	if (sscanf(arg, "%s with %s", item, tessera) < 2)
	{
	if (! objectp(dest = present(arg, me)))
		return notify_fail("������û���������ߡ�\n");
		baoshi = filter_array(all_inventory(me),(:$1->query("can_be_inlay"):));
		if(sizeof(baoshi))
		{
			msg = ZJOBLONG"��ѡ����Ҫ��Ƕ�ı�ʯ��\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
			for(i=0;i<sizeof(baoshi);i++)
			{
				msg += baoshi[i]->query("name")+"("+baoshi[i]->query("can_be_inlay/skill")+"):inlay "+arg+" with "+baoshi[i]->query("id");
				if(i<(sizeof(baoshi)-1)) msg += ZJSEP;
			}
		}
		else
		{
			msg = ZJOBLONG"����������û�б�ʯ�����ܽ�����Ƕ��";
		}
		tell_object(me,msg+"\n");
		return 1;
	}
	
   if (sscanf(arg, "%s with %s", item, tessera)==2)
   {
   
     int hole;
  if (! objectp(dest = present(item, me)))
		return notify_fail("������û���������ߡ�\n");   
     
		
     hole=dest->query("magic/hole");
    i = 1;
     msg = ZJOBLONG+dest->name()+"һ����"+hole+"����λ����ѡ����Ҫ��Ƕ�Ŀ�λ��\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
			while(i <= hole)
			{
			 if (mapp(dest->query("hole/"+i)))
              {
              i++;
			  continue;
			  }
			   msg += "��λ"+chinese_number(i)+":inlay "+item + " with " + tessera + " set "+i;
			   if (i < hole)
				msg += ZJSEP;
				i++;
			}
			tell_object(me,msg+"\n");
			return 1;
   }
   
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : inlay <����> with <������Ʒ> set <��λ>

���ָ��������㽫ĳ��������Ʒ��Ƕ������һ�ֵ����ϣ�ʹ�õ���
���������������
HELP
    );
    return 1;
}
