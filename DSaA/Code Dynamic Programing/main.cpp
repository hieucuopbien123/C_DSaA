#include <stdio.h>
#include <limits.h>

//tìm số lượng đồng xu min để tổng m bằng bnh
//bài toán con: giả sử có m=14 thì bài toán con m=0,..,9
//m = 0; thì 0 đồng xu
//m = 1 giải từ m = 0 là lấy số nhỏ nhất trong 3 số cộng vào m = 0 để đc m = 1
//m = 2 giải từ 2 cái trc, lấy từ m = 1 cộng thêm 1 đồng 1 nx nhưng lấy từ m = 0 tốt hơn vì chỉ có 1 đồng 2
//m = 3 nếu đi từ m = 0 thì thêm 2 đồng mà thực chất thêm 2 đồng tức là đi từ m = 1 or = 2 r nên k tính luôn
//còn nếu đi từ m = 1,2 thì chỉ cần thêm 1 đồng=> ta sẽ chỉ tính TH dùng thêm 1 đồng bởi vì thêm hai đồng tức
// là đi từ cái bên trên r tức là = min(m=2 +1, m=1 +1)
//m = 4 từ 0 thì thêm 2, từ 1 thì thêm 3 mà 3 min thì thêm 1 là 1, từ 2 thì thêm 1, từ 3 thêm 1 tức là 
//min(m=1 +1,m=2 +1, m=3 +1)(để giải m=3 thì lại phải giải m=1,m=2->tc gối nhau, cả tc ctr con tối ưu dễ thấy)
//cứ giải nv đến khi m = 14 là kq-> k tối ưu=>occho vì đi đến m=4 có ĐK bắt buộc là phải thêm 1 đồng vào cái trc
//Lưu kết quả: vào 1 mảng gồm 15 phần tử và cần giải f[14];
//Từ con lên mẹ: như v để giải f[5] từ f[0..4] thì ta phải so sánh các f[1]+f[4],f[3]+f[2],...
//thuật toán chung là for 0->sum vì tính tất cả f[0]->f[sum](sum+1 phần tử)->nếu trùng với tiền thì ==1 luôn
//nếu khác 1 thì làm cái bc trùng ss(k dùng j đến tiền nx mà chỉ dùng các phần tử của mảng)-> ss từ 1 đến i-1
//và quét 1 nửa lấy ra min-> gán bằng min=> liệu các TH đã bao hêt-> bao hết r vì chỉ có 2 TH: re 1 là trùng
//hai là k trùng thì lấy ss gán min, k thể nào rời khỏi TH đó đc-> dùng sum phần tử cx đc, k cần sum+1
//cách thủ công: phải quét từ for(int i=0;i<m/1;i++) tương tự 4 vòng lông nhau
int getMinCoin(int coin[],int num,int sum)
{//chưa tối ưu, nếu có 100 phần tử thì phải cộng 50 lần nhưng nếu làm chuẩn thì chỉ mất 3 lần
//các bài toán mẹ chỉ dùng 1 phần các bài toán con trong dãy.(k sửa nx)
    int re[sum + 1] = {};
    re[0] = 0;
    int min = INT_MAX;
    for(int i = 1; i <= sum; i++)
    {
        for(int j = 0; j < num; j++)
        {
            if(coin[j] == i) 
            {
                re[i] = 1;
            }
        }
        if(re[i] == 0)
        {
            for(int k = 1; k <= i/2; k++)
            {
                int temp = re[k] + re[i - k];
                if(temp < min)
                {
                    min = temp;
                }
            }     
            re[i] = min;
            min = INT_MAX;
        }
    }
    return re[sum];   
}
//hướng đi khác: sẽ ra sao nếu như ta làm như trên mà k thể tìm ra lời giải cho mẹ từ con-> nguyên nhân là vì 
//ta tư duy sai. Khi bài toán yêu cầu tìm số lượng đồng xu thì ta nên tư duy là mỗi 1 lần thì làm gì? Sao cho 
//vc làm đó k bị tăng độ phức tạp khi n tăng mà độ phức tạp là hằng số. ở đây
//mỗi 1 lần ta thêm vào 1 đồng xu nx để đạt giá trị yêu cầu->điều đó có nghĩa để giải bài toán mẹ, ta k cần phải
//giải từ tất cả bài toán con r xem Th nào nhỏ nhất như trên, nếu lúc nào cx xem tất cả các bài toán con nv thì
//lâu vl=> sau mỗi lần ta chỉ thêm đc vào 1 đồng xu vào TH con nào là ok nhất vì qhđ bài toán này đã chỉ dùng đc Khi
//tính bài toán mẹ từ con. Ta cho rằng liệu thêm 1 đồng vào TH 3 đồng k tốt bằng thêm 2 đồng vào TH 1 đồng-> điều đó
//là sai ht. "Thêm 1 đồng xu vào các f[i] trc đó" là 1 quy tắc bất di bất dịch. Để tính đc f[n] thì ta bắt buộc phải
//thêm vài đồng xu vào các f[trc đó]. Ví dụ ta có coin{1,3}, để tạo ra 5 thì buộc thêm 2 đồng vào f[3] nhưng thật ra
//là thêm 1 đồng vào f[4] vì f[4] tạo từ f[3] nên như nhau. Vc ta chỉ định thêm 1 đồng từ nhỏ đến lớn khiến cho f[i]
//luôn luôn là số lượng đồng xu nhỏ nhất cần có để tạo ra i r. Vc tìm ra thêm 1 đồng cx là vc giải ra bài toán. Để 
//tìm ra thì phải tìm cách đi từ bài toán con cực ít phần tử giải bài toán mẹ là ta đang làm cái bước gì, sau đó
//gộp các phép chung lại và loại bỏ các phép thừa thãi sao cho cấu trúc con tối ưu chặt chẽ và bao hết các Th.
//Ở đây ta gộp vc thêm 2 phần tử vào thành chỉ cần thêm 1 phần tử-> tìm ra điều đó bằng cách đi từ bài toán con 
//1,2 phần tử mà thôi. Ở đây: ta đã có 1 list 0->n-1 là số lượng coin min để có 0->n-1 r, cần thêm 1 coin vào vị trí
//nào để đc n đây-> có 3 coin thì chỉ thêm đc vào các vị trí là n-1,n-2,n-5=>để tìm đc f[n] thì buộc phải tìm đc
//f[n-1], f[n-2], f[n-5] và test thử thêm vào cái nào là min thì lấy. Giả sử ta thêm 2 đồng cơ thì cx buộc phải Tính
//đc 3 cái f đó r thêm vào tức quy về thêm 1 đồng k tránh đc ->cấu trúc con tối ưu tính bắt buộc sau mỗi lần làm hanh
//động gì thì ta bắt buộc phải có cj. Điều này k khó vì để tính f(5) ta buộc phải có f(4) xong bảo là thêm 1 đồng vào
//f(4) thì mới có f(5) => đó là 1 quy trình dễ nghĩ ra và bắt buộc

//Luyện tập:Tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S,k qt thứ tự đồng xu
//bài toán con: giả sử s=14
//m=0=> thì có 1 cách lấy từ 0 đồng xu-> k chơi ở đây
//m=1=> thì từ m=0 có 1 cách
//m=2=> thì từ m=0 có 1 cách là 1 đồng 2, từ m=1 có 1 cách là thêm 1 vào=>tổng là 2 cách
//m=3 thì từ m=0 có 0 cách, từ m=1 phải có m=2 có 1*2 là 2 cách->tổng là 2 cách
//m=4 thì từ m=0 có 0 cách, từ m=1 có 2 cách từ m=2 có 2 cách-> 4 cách nhưng do m=2 có 2 cách lặp đi lặp lại nên
//coi là 1. tức là ta k lấy nhân mà lấy hoán vị 2 cái của nó 2C2 bằng 1->tính toán sai r TH trùng k giải quyết đc
//lưu kết quả vào mảng f[m]
//từ con lên mẹ cụ thể: chạy vòng for các giá trị trước đó và lấy int tempSum+=1C<số cách tạo i>+1C<số cách tạo j-i>
//trc tiên coi m=0 nếu trùng đồng xu thì tempSum+=1 đã. nếu i==j-i thì tempSum+=2C<số cách tạo i>
//Cố giải:ta giả sử có 4 đồng xu. Bài toán con là có 1 đồng xu
//chỉ có 1 đồng xu 1 thì kết quả là m chỉ có 1 cách
//có thêm đồng 2 thì kết quả từ 1 đồng xu là lấy 2 chia 1 đc 2, ta nhét 2 vào từ từ đến khi chỉ toàn 2 or toàn 2 và
//1 đồng 1 thì mỗi lần thêm là 1 cách + vào
//có thêm 1 đồng 5-> từ 1 đồng 1 làm tương tự thêm 1 đồng 2, nếu từ mỗi lần 1 có 2 thì thêm 1 đồng 5 vào có 
//cần gộp chung và loại bỏ các bước thừa

//đi từ bài toán đệ quy
//7->kiểm tra 7 với w=5->nếu lón hơn thì đi tiếp->kết quả là có 5 và k có 5->Nếu có 5-> kết quả là 7-5=2-> ss với
//3 và nhỏ hơn 3-> lấy w giảm từ 3 xuống 1-> return 1 luôn-> Nếu k có 5 thì có 3 hoặc k có 3-> Nếu có 3->7-3=4->
//ss thấy lớn hơn 3: có 3 hoặc k có 3-> Nếu có 3-> 4-3=1 -> ss nhỏ hơn 3 return 1->nếu k có 3 thì return 1->nếu
//k có 3 tiếp thì return 1
//cụ thể: truyền vào 7 và 5->ss 7 và 5: nếu 7>5 thì có 5 or k có 5-> TH có 5 thì 7-5=2->2 lại ss vs 3-> do 2<3 nên
//return 1->Th k có 5 thì ss vs 3-> nếu lớn hơn 3 thì có 3 hoặc k có 3-> có 3 thì ...
int getMinWayRecursive(int num, int w, int coin[])
{
    int temp = 0;
    if(num >= w)
    {
        if(w == 1)
        {
            return 1;
        }
        for(int i = 2; i >= 0; i--)
        {
            if(w == coin[i])
            {
                temp = coin[i - 1];
                break;
            }
        }
        return getMinWayRecursive(num - w,w,coin) + getMinWayRecursive(num,temp,coin);
    }
    else{
        if(w == 3)
        {
            return 1;
        }
        for(int i = 2; i >= 0; i--)
        {
            if(w == coin[i])
            {
                temp = coin[i - 1];
                break;
            }
        }
        return getMinWayRecursive(num,temp,coin);
    }
}
//Ở bài đệ quy thì f: trả ra số cách lấy num dùng đến temp coin

//1 mảng 2 chiều lưu f[m][n] là số cách tạo ra khối lượng n dùng đến m xu(k dùng xu thứ m+1)
//cái đệ quy nó bị trùng ở chỗ có thể phải tính trùng nhau
//bài toán con: giả sử tính m = 0 thì f từ 0 đến 2 đều là 1
//m=1 thì dùng xu 1 là 1, dùng đến xu 3, xu 5 cx chỉ là 1
//m=2 thì dùng xu 1 là 1, dùng xu 3 và 5 là 1 
//m=3 thì xu 1 là 1,nếu dùng 2 loại xu 1 và 3 thì từ xu 1 ta có thể thêm xu 3 vào 1 lần là 2,nếu dùng 1,3,5vẫn là 2
//m=4 thì f[0][4]=1;f[1][4] đi từ f[0][4] là 2 vì ta thêm đc đồng 3 vào mỗi 1 lần
//m=5 thì f[0][5]=1;f[1][5]=2;f[2][5]=3;
//m=6 thì f[0][6]=1;f[1][6]=3;f[2][6] thì từ 3 TH của f[1][6] ta lấy 6/5=1 và 6-1 = 1 tức là kết 
//quả f[2][6]= f[1][6]+f[2][1]=2(-> bắt đầu dùng đc các cái trc lưu vào mảng). Tức là ta dùng có 5 và k có 5
//m=7->f[0][7]=1;f[1][7]= lấy 7/3=2 nên 1+2 là 3;f[2][7]; thì f[1][7]+f[1][2]=4;=> nghĩ lại ta hoàn toàn dùng
//đc vs Th f[2];tức là (TH có 2->có 1 2, có 2 2,có 3 2,...)+(Th k có 2) f[1][7]=f[0][7]+f[1][4]=3
//đó là bản chất tính chồng nhau, nếu k tìm ra điểm chồng có thể dùng đi dùng lại này thì phải tính nh lần rất tốn
//ta tìm ra điều đó nhờ đi từ đệ quy, nếu k thì ta phải tính chay đc or làm cj để ra đc đã chứ nhìn phát đòi ra 
//ngay qhđ thì hơi khó. Điều nx là ta có thể chia nhỏ nhiều đối tượng, chia nhỏ xu or chia nhỏ tổng khi làm bài
//nếu như ta thấy mảng 1 chiều tính m=14 từ các m trc khó->thì ta sẽ chia nhỏ hơn nx là dùng 1 đồng để tính 1 f có
//dễ hơn k và thêm đủ đồng đến khi tính đc f->từ đó tính ra các f lớn hơn tt. 

//Tức là đi từ bài toán con thứ nhất là số phần tử nhỏ nhưng vẫn khó. Ta lại chia nhỏ bài toán đó ra là với ít đồng
//xu hơn chỉ có 1 đồng->ez rồi, xong đi lên 2 đồng-> cứ thế ta thấy tính 2 đồng cần dùng đến 1 đồng. Tính mass nhỏ
//lại cần đến mass lớn=> mảng 2 chiều=>bc
//Chú ý: ta phải tùy TH vc dùng nhiều xu hơn kp là tổng của tất cả các TH ít xu mà là dùng từ các TH đó. Sau đó
//kết quả của ta chỉ là TH dùng cả ba đồng xu. Ví dụ: ta k nói f[n][2] là dùng cả 3 đồng xu mà ta nói là dùng đến
//đồng xu thứ 3 tức có đồng 5 hay 3 hay k thì bao hết r=>cần chú ý Trap khi chia ra như v tránh nhầm

//LÀM SAO ĐỂ NGHĨ RA NHƯ V:(PRO)
//Điều quan trọng là ta xác định đc cái đối tượng của ta có gì đặc biệt-> f[i][j] là dùng từ 0 đến i đồng xu để tạo
//ra khối lượng j-> nếu ra đc điều đó là ra tất cả-> để đc điều đó thì ta phải chia ra đủ các TH: Số cách để tạo ra
//j thì nó CÓ CÁC TH LÀ chứa đồng xu lớn nhất hoặc k chứa đồng xu lớn nhất(PP đơn giản hóa vấn đề chia nhỏ bài toán
//nx ra như v)-> từ đó ta biết nếu k chứa đồng xu lớn
//nhất thì đó là 1 bài toán con dễ hơn r-> và k chứa đồng xu lớn nhất tức là nó có thể k chứa đồng xu ngay sau đồng
//xu lớn nhất-> cứ như v ta ms nghĩ đến vc tạo ra mảng 2 chiều để lưu vì chắc chắn có 1 chiều để đi từ 0 đến m của
//ta r nên ta cần thêm 1 chiều nx tg ứng số xu. Chia nhỏ mọi thứ đến khi nó tính dễ thì thôi->dần dần giải tăng lên

//đi từ nhỏ đến lơn or đi từ vc tính toán chay khi gặp bài toán bất kỳ
//Đầu tiên ta đi từ vc tính toán chay thì ta nghĩ là có thể chỉ toàn 1, chỉ toàn 3 or cả 1 và 3 đều là thứ cần cộng
//vào kq->phải chia TH. Giả sử biết phải chia TH r thì chia ntn->đương nhiên là chia ra có 1 đồng xu, và có cả 1
//và đồng 3(TH có cả 1 và 3 đã bao TH chỉ có 3 r)-> cứ như thế ta ms nghĩ là phải tính từ đồng nhỏ đến lớn->sau đó
//kết quả của ta là có cả 3 đồng cơ->thì để tính đc nó phải dùng 2 kq trc tức là phải lưu vào 1 mảng->mảng 2 chiều
//Chú ý cách nghĩ: có 1 đồng, có 3 đồng, có cả 1 và 3 đồng. Ta cần nghĩ theo 1 thứ tự theo kiểu thứ tự 1 chiều để
//xét, đó là dùng đến 1 đồng->dùng đến đồng thứ 2. Khi chia như v ta đảm bảo được yếu tố 1 chiều là số đồng đc cộng
//lên nhưng đi đến đâu là bao hết TH đến đó k bị lặp
int getMinWay(int num, int coin[])
{
    int f[3][num + 1];
    for(int i = 0; i < num + 1; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                f[j][i] = 1;
            }
            else
            {
                int temp = i - coin[j];
                if(temp >= 0)//cứ bao hết TH là đc
                {
                    f[j][i] = f[j - 1][i] + f[j][temp];
                }
                else
                {
                    f[j][i] = f[j - 1][i];
                }
            }
        }
    }
    return f[2][num];
}

//tương tự vs cách nghĩ pro bên trên ta làm bài bên dưới
//Ta lại phải chia để bao TH: khi ta đi từ 1->2->3 phần tử thì ta thấy max sub có các TH là chứa phần tử ms nhất
//hoặc k chứa phần tử ms nhất->từ đó ta ms nghĩ đến vc để chứa phần tử ms nhất thì nó phải chứa phần tử sát phần 
//tử ms nhất->tức là ta cần 1 mảng để lưu các phàn tử kết thúc bằng phần tử nào->tuy nhiên ta lại thấy nó k dùng
//đến các phần tử ở xa mà chỉ cần dùng tức thời ss nếu lơn thì lấy, k thì k lấy-> k lấy là bỏ nên chỉ cần lưu vào
//biến là đủ r

//bài tìm max sub arr: cho 1 arr, tìm sub có max lớn nhất là bao nhiêu
//giả sử brute force thì ta cần tạo ra mọi các tổng dãy con và ss.Như v 1 vc tính tổng của 2 số có thể phải nh lần
//nếu dùng đệ quy thì là ta chia nhỏ phần tử nhưng vc tính tổng 2 số vẫn lặp lại khi duyệt qua các số liên quan
//nếu dùng qhđ thì sẽ chỉ tính duy nhất 1 lần khi qua 2 số, nó là bài toán cải tiến của đệ quy
//bài toán trùng nhau ở đây là qtr tính bị trùng.Thay vì tính đi lại ta sẽ lưu nó nhưng ở đây ta k lưu vào 1 mảng
//mà chỉ lưu vào 1 giá trị vì cuối cùng các giá trị k dùng đi dùng lại nh lần khi dùng qhđ
//Chính vì v, tùy vào cách giải từ con lên mẹ ntn mà có hướng lưu phù hợp. ở trên ta lưu 1 mảng vì có thể dùng
//các giá trị xa lắc xa lơ
//m=1 thì max là chính nó
//m=2 từ m=1; thì có 3 TH là m=1,m=2,(m=1)+(m=2), giá trị nào lớn nhất thì lưu vào re=>ta sẽ lưu lại giá trị m=1;
//ta so sánh (m=1)+(m=2) vs m=2 và lưu số lớn hơn vào temp. ss temp và re lớn hơn thì lưu vào re
//m=3 từ 2 cái trc; thì có các TH là re cũ của ta là max, or kết thúc bằng m=3 là max-> như v đúng ra là từ con
//đến mẹ ta xét 2 TH là có m hay k có m hiện tại, đúng ra là kết thúc tại m hiện tại. Ta ss nếu k kết thúc tại m
//hiện tại thì là kết quả ta dùng từ trc, nếu kết thúc tại m hiện tại thì ta tính từ cái max kết thúc bằng m-1
//ta tính ra kết thúc bằng m max-> ss lại lưu re
//cần 1 biến re lưu kết quả, 1 biến temp lưu kết thúc bằng m nào
//luồng: ta for các phần tử từ nhỏ đến lớn; giả sử có 1 ptu, thì gán re;thêm 1 phần tử->max(phần tử cũ, cũ+ms) là
//temp, ss temp vs re và lưu vào re; thêm 1 phần tử thì tương tự ss max(temp,phần tử ms)
int getMaxSub(int arr[],int num)
{
    int re = arr[0];
    int temp = arr[0];//max sub kết thúc tại arr[i], do ta ss và lưu vào re liên tục nên nếu max sub tại arr[i]
    //bị mất sau mỗi vòng lặp cx k sao vì đó kp kết quả r
    for(int i = 1; i < num; i++)
    {
        if(arr[i] < temp + arr[i])
        temp += arr[i];
        else temp = arr[i];
        if(re < temp)
        re = temp;
    }
    return re;
}

//tìm dãy con k giảm dài nhất:cho dãy int đầu vào,ta phải lấy ra số lượng phần tử của dãy con k giảm dài nhất mảng
//m=1 thì dãy con là nó
//m=2 tức là thêm 1 phần tử nx vào thì ta ss, nếu f[2]>=f[1] lưu dãy này lại, ta so sánh với chuỗi m=1 và chuỗi
//kết thúc bằng m=2, cái nào lớn thì lưu vào re(sl phần tử)
//m=3-> ta ss nếu f[3]>=f[2] thì nối nó vào chuỗi kết thúc m=2, nếu nó lớn hơn chuỗi re thì gán re
//lưu kết quả tính vào 1 số int là đc vì cần lấy mỗi số lg phần tử
int getIncreaseSubArr(int arr[], int num)
{
    int re = 1;
    int temp = 1;
    for(int i = 1; i < num; i++)
    {
        if(arr[i] > arr[i - 1])
        {
            temp++;
        }
        else{
            temp = 1;
        }
        if(temp > re)
            re = temp;
    }
    return re;
}

//áp dụng PP pro vào bài  dưới:
//để giải ra đc khi đi từ 2->3->4 ô thì ta thấy lượng táo max ở ô thứ n chỉ xảy ra 2 TH-> 1 là số táo ở ô trên nó
//cộng vs ô hiện tại hoặc là bên trái nó->Chia đc TH như v ta ms nghĩ đến mảng 2 chiều đi đến ô đó thì ss ô trên 
//và ô trái r cộng vào. Ta nghĩ thêm nếu ở hàng trên cùng và bên trái thì k ss thì chia ra thôi 

//Cho một bảng M∗N,mỗi ô có một lượng táo.Bắt đầu từ ô trái trên,mỗi bước có thể đi sang phải hoặc xuống dưới. 
//Bạn có thể ăn được nhiều nhất bao nhiêu quả táo ? not ez
//như v đối số vào là 1 mảng và trả ra cách ăn đc nh táo nhất. Rõ ràng với cách đi như v ta có thể đi đến bất cứ
//nơi đâu trên bảng và để ăn nh táo nhất bắt buộc phải đi đến lúc k đi đc nx, túc là ô dưới cùng
//bài toán con: giả sử chỉ có 1 ô thì kết quả là ô đó
//giả sử có n=0,m=1->có 1 cách đi->kq là tổng 2 ô đó
//n=1,m=1->re[n]=app[n]+max(1 trong 2 ô)->ta nhận thấy nếu như v thì ta chỉ đi có 1 hướng mà có thể các hướng khác
//lúc đầu ít táo nhưng lúc sau nh táo->BC của qhđ, bn có thể ăn nh nhất bao nhiêu quả táo thì ta phải tạo ra 1 mảng
//bao hết tất cả TH, mỗi phần tử của mảng là số lượng táo max ta ăn ở từng Th và từ đó ta suy ra số lượng táo max
//ở ô cuối cùng->Chứ qhđ k chỉ là ta làm theo 1 đường đi.
//Nhưng điều đó dễ dàng ở chỗ các bài toán con gối nhau và cấu trúc con tối ưu->nếu ta muốn tìm số táo max ở ô[i][j]
//thì ta có thể đi từ ô [i-1][j-1], nếu ta làm theo các cách khác thì rất khó vì ta phải tìm đg đi từ ô [0][0],nhưng
//ở đây ta đã chắc chắn ô [i-1][j-1] là ô chứa số táo max có thể đi đến ô đó r thì vc đí đến ô tiếp theo chỉ cần
//đi từ ô đó, k cần đi từ ô 00 nx là ok
//->thế ms cần xđ rõ mảng/biến lưu cj thể hiện tính chất cấu trúc con tối ưu trong qhđ.Còn trong đệ quy thì phải 
//xđ rõ hàm làm gì thể hiện tính chất từ con lên mẹ
//tạo mảng re[n][m]->re[1][1]= re[1][0]+max(2 ô kề)->tt
//tính sai, k bắt buộc đi từ ô chéo mà chỉ cần bên trên or bên trái
int maxApple(int apples[][6],int m,int n)//truyền mảng 2 chiều phải khai báo phần từ phía sau
{
    int re[m][n] = {};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //ta cần chỉnh sao cho dùng cả qhđ ở những TH đầu tiên ms là tối ưu nhất
            if(i == 0)
            {
                if(j == 0)
                {
                    re[i][j] = apples[0][0];
                }
                else{
                    re[i][j] = re[i][j - 1] + apples[i][j];
                }
            }
            else if(j == 0)
            {
                re[i][j] = re[i - 1][j] + apples[i][j];
            }
            else{
                re[i][j] = apples[i][j] + ((re[i - 1][j] > re[i][j - 1]) ? re[i - 1][j] : re[i][j - 1]);
                //điều đb là khi dùng ?: thì nhét vào(?:) chứ để ngoài thì nó hiểu phép + từ apples vào r ms ?
            }
        }
    }
    return re[m - 1][n - 1];
}


int main()
{
    //quy hoạch động: dùng phương pháp chia để trị như đệ quy, cụ thể là chia phần tử. Điều kiện:
    //1> có các bài toán con gối nhau=> các bài toán con là điều kiện cần để giải bài toán lớn, và 
    //chúng đc gọi đi gọi lại nh lần khi giải chay
    //2> có các cấu trúc con tối ưu: dùng các bài toán con ít phần tử để giải quyết bài toán lớn.
    //=>tìm đường đi ngắn nhất từ a đến b và giữa ab có cde thì ta phải tìm đg đi ngắn nhất từ a đến
    //c,d,e và từ c,d,e đến b r suy ra kq->k có bất cứ 1 cách nào tìm từ a->b mà k tính cde->tính cde 1 lần r lưu
    //Vd: binary search k dùng đc qhđ vì các bài toán con k gối nhau vì nó k gọi đi gọi lại nh lần. Ví dụ ta cứ 
    //chia đôi ra r tìm nhưng đó là lần duy nhất vc tìm kiếm vs các phần tử đó đc thực hiện(giả sử k dùng qhđ).Còn 
    //fibonacii thì tính f(4) yêu cầu phải tính f(3)+f(2) và 2 cái f(3),f(2) đều gọi f(1)-> f(1) gọi nh lần và
    //vc tính các f nhỏ là điều kiện bắt buộc để tính f lớn k thể tránh đc.
    //->qhđ sẽ lưu kết quả và dùng luôn nên vc gọi nh lần k phải tính toán lại
    //các bước: chia bài toán lơn thành bài toán con-> lưu lời giải bài toán con lại->giải bài toán lớn từ con
    //vc xác định phép toán con gối nhau có thể gây khó khăn vì ta nghĩ nó như đệ quy, ta phải nghĩ đúng là đi từ
    //1 phần tử, 2 phần tử lên dần xem liệu tính cái phần tử thứ 5 liệu có dùng đến 1 nhiều lần k(dùng 1 lần khi 
    //giải chay thì k gối nhau), or nếu k cần dùng để giải ra 5 đc thì cx là k có cấu trúc con tối ưu r(đó là khi 
    //chưa dùng QHĐ, nếu dùng r thì cần tái sử dụng 1 lần cx đc)

    //cơ bản nhất: tính giai thừa n!->lấy f[n+1], tính các 1!,2!,... lưu vào f[1],f[2],... Tính f(n) phải dùng
    //đến f[n-1] nên là câu trúc con tối ưu. Nhưng chỉ cần tính f[n-1] mỗi 1 lần và f[1] tính mỗi 1 lần khi giải
    //tìm f[n] nên k gối nhau-> đó là nguyên nhân dùng đệ quy và dùng qhđ ở TH này là như nhau nhưng qhđ lỗ về mặt 
    //bộ nhớ,Nhưng nếu nó yêu cầu ta tính 1 lúc 2 giá trị giai thừa n! và m! thì lại là bài toán con gối nhau vì
    //tính đi tính lại các giá trị chung 2 lần, nên qhđ sẽ lợi hơn đệ quy. Sự chênh lệch lớn nếu m,n cực lớn
    
    /*//tìm số lượng đồng xu min để tổng m bằng bnh
    int num = 4;
    int coin[num] = {1,2,5,10};
    int sum = 0;
    printf("Input m: ");
    scanf("%d",&sum);
    printf("Min number of coin is %d\n", getMinCoin(coin,num,sum));*/
    
    /*Tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S
    int coin[num] = {1,2,5,10};
    printf("%d",getMinWay(10,coin));*/
    
    /*//getIncreaseSubArr
    int arr[10] = {3,54,6,7,8,9,10,5,4,6};
    printf("getIncreaseSubArr: %d\n", getIncreaseSubArr(arr,10));*/
    
    /*//maxApple
    int apples[5][6] = { 0, 0, 0, 1, 2, 3,
                         1, 2, 4, 5, 6, 3,
                         2, 3, 4, 5, 6, 3,
                         2, 3, 4, 5, 6, 3,
                         100, 1, 1, 1, 1, 3};
    printf("%d\n", maxApple(apples,5,6));*/

    return 0;
}
//tổng kết: hiểu đc điều kiện dùng,sự khác biệt nếu dùng đệ quy và qhđ(ví dụ giai thừa),các bước áp dụng qhđ,lỗi 
//khi dùng tất cả mà chỉ cần dùng 1 vài f trc+lưu vào loại gì,tư duy mỗi lần thì nên làm gì,cấu trúc con tối ưu 
//bắt buộc phải tính cj,ghi rõ cơ chế 1 vd ra r code,tư duy:tính toán->chia các TH->đặt biến lưu là gì,xác định
//rõ biến có vai trò gì trong cấu trúc con tối ưu(đệ quy thì xđ hàm)->áp dụng,viết ra từng m=nhỏ đến lớn để giải

//2 bước: 1)tạo biến lưu giá trị của quy hoạch động ;2)xử lý bài toán lớn dựa trên biến giá trị của bài toán con
//Để làm (1):Ta phải chia các đối tượng của bài toán ra đủ nhỏ để giải đc=>quyết định lưu bằng mấy chiều + lưu 
//biến tạm thời hay mảng lâu dài
//Để làm (2):Ta phải khởi tạo các giá trị cơ bản cho các biến lưu(vì có lúc có những giá trị ban đầu mà mẹ k đi 
//từ con) + giải bài toán mẹ từ con sao cho vc giải đó là bắt buộc ! đi từ con đến mẹ=>ta tưởng tượng ta có đáp 
//án tất cả các bài toán con rồi,và đặc biệt sử dụng bài toán con ngay sát nó để giải bài toán mẹ chỉ vs 1 bước.

