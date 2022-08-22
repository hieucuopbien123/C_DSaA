#include <bits/stdc++.h>
using namespace std;

//cho 1 số decimal và tìm pattern binary. 
//Naive: ta chuyển từ decimal sang binary dạng string r search string cần tìm trong string đó
//Ta có 1 góc nhìn mới hơn: chuyển từ cụm binary sang decimal. 
int countPattern(int n, string pat)
{
	//pattern dạng int
	int pattern_int = 0;
	//biến số 2 mũ mấy tăng dần phục vụ quá trình convert thôi
	int power_two = 1;
    //biến lưu số decimal mà tất cả bit đều là 1
	int all_ones = 0;

	for (int i = pat.length() - 1; i >= 0; i--) {
		int current_bit = pat[i] - '0';
		pattern_int += (power_two * current_bit);
		all_ones = all_ones + power_two;
		power_two = power_two * 2;
	}
	cout << pattern_int << " " << all_ones << " " << power_two << endl;
	//đến đây là có all ones lưu decimal mọi bits là 1 và pattern dạng decimal r

	int count = 0;
	while (n && n >= pattern_int) {
		// If the pattern occurs in the last digits of n
		if ((n & all_ones) == pattern_int) {
			count++;
		}
		// Right shift n by 1 bit
		n = n >> 1;
	}
	return count;
}

// Driver code
int main()
{
	int n = 500;
	string pat = "101";
	cout << countPattern(n, pat);

    return 0;
}
//Cơ chế: để binary của 1 số chứa binary của 1 số khác thì số đó phải lớn hơn số khác kia
//Ở bài này ta liên tục check xem 1 số có pattern nằm ở cuối số còn lại hay k r lần lượt xóa bit cuối
//của nó đi cho đến khi về 0 or kích thước nhỏ hơn kích thước chuỗi binary
//VD: so sánh 1010110 có chứa 110 ở cuối k thì ta lấy all ones là 111
//Ta tính 1010110 & 111 thì được: 0000110 -> check thì 2 số bằng nhau về giá trị nên có xuất hiện
//Cách này cho time space O(n) và phức tạp không gian O(1)

//Lỗ hổng: nó chỉ check patter bắt đầu bằng số 1 vì bản chất ta so sánh giá trị số decimal mà nên các pattern
//bắt đầu với 0 như 011 thì éo check đúng
//Ta có thể vá bằng cách đảo bit 1 và 0 cho nhau ở cả 2 số và check bth chẳng hạn

