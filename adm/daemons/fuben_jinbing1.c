
inherit F_DBASE;

#define fb_time 1600;  //ʮ���Ӹ���ʱ��

string master;
object *room;
int times;
int num = 2;
int ko=0;
string enter;

void out_time(object me,object ob);

void create()
{
	set("channel_id", "����");
	master = 0;
	room = ({});
	times = 0;
}

void dest_fb(object me)
{
	object *ob_list,room;
	int i;
	
	if (me) {
		ob_list = children("/adm/daemons/fuben_jinbing1");
		if (sizeof(ob_list) > 0) {
			for(i=0; i<sizeof(ob_list); i++) {
				if (ob_list[i]->query("id") == me->query("id"))  {
					ob_list[i]->des_fb();
				}
			}
		}
	}
}

int des_fb()
{
	int i,j;
	int size = sizeof(room);
	int size2;
	int lvl2;
	object *all_inv,m_master;

	for(i=0;i<size;i++) //ɾ����������
	{
		if(!room[i]) continue;
		all_inv = all_inventory(room[i]);
		size2 = sizeof(all_inv);
		for(j=0;j<size2;j++) //ɾ�����ڵ����Ｐ��Ʒ
		{
			if(userp(all_inv[j])) 
			{
				all_inv[j]->move("/d/city/wumiao");
			}
			else
				destruct(all_inv[j]);
		}
		destruct(room[i]);
	}
	destruct(this_object());
	return 1;
}

//��ʼ��
int init(object me)
{
	int i,j,k,k1,k2;
	string *files,*list=({}),*dirs;
	object roomb;
	string *room_a=({}), *tmp=({});
	object systeam = this_object();
	master = me->query("id"); //��¼����id
	times = time()+fb_time;//����ʱ��
	//�����������
	files = get_dir("/fuben/jinbing1/");
	for(i=0;i<sizeof(files);i++)
	{
		if(file_size("/fuben/jinbing1/"+files[i])>0)
		{
			roomb = new("/fuben/jinbing1/"+files[i]);
			room += ({roomb, });			
			list += ({ file_name(roomb) });			
			if(files[i]=="enter.c")
			{
				enter = file_name(roomb);
				set("enter", enter);
			}
		}
	}
	for(i=0;i<sizeof(list);i++)
	{
		if(roomb=find_object(list[i]))
		{
			dirs = keys(roomb->query("exits"));
			for(j=0;j<sizeof(dirs);j++)
			{
				for(k=0;k<sizeof(list);k++)
				{
					if (strsrch(list[k], roomb->query("exits/"+dirs[j])+"#")==0) {						
						roomb->set("exits/"+dirs[j], list[k]);
					}
				}
			}
		}
	}
	//���븱��
	me->move(enter);
	//����ѭ��
	out_time(me,this_object());
	return 1;
}

//����ѭ��
void out_time(object me,object ob)
{
	int i,j;
	int size,size2,is_ok;
	object *all_inv;
	
	if(!ob || !clonep(ob))
	{
		return;
	}
	//��鸱��ʱ�䣬��Сʱ������
	if(times < time())
	{
		des_fb();
		return;
	}
	//�������Ƿ��ڸ�����
	is_ok = 0;
	size = sizeof(room);
	for(i=0;i<size;i++)
	{
		if(!room[i]) continue;
		all_inv = all_inventory(room[i]);
		size2 = sizeof(all_inv);
		for(j=0;j<size2;j++)
		{
			if(userp(all_inv[j]))
			{
				is_ok = 1;
				if (times > time()) {
					ko++;
					if (ko>=12) {
						ko=0;
					}
				}
				break;
			}
		}
	}
	call_out("out_time",5, me, ob); //һ������һ��
}
