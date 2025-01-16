struct Solution {
    count: i64,
}

impl Solution {
    fn new() -> Self {
        Solution { count: 0 }
    }

    fn check_count(&mut self, nums: &mut Vec<i32>, start: usize, mid: usize, end: usize, d: i32) {
        let mut l = start;
        let mut r = mid + 1;
        
        while l <= mid && r <= end {
            if nums[l] <= nums[r] + d {
                self.count += (end - r + 1) as i64;
                l += 1;
            } else {
                r += 1;
            }
        }
        
        // Sort the slice from start to end
        nums[start..=end].sort_unstable();
    }

    fn merge_sort(&mut self, nums: &mut Vec<i32>, start: usize, end: usize, d: i32) {
        if start >= end {
            return;
        }
        
        let mid = start + (end - start) / 2;
        self.merge_sort(nums, start, mid, d);
        self.merge_sort(nums, mid + 1, end, d);
        
        self.check_count(nums, start, mid, end, d);
    }

    fn number_of_pairs(&mut self, a: Vec<i32>, b: Vec<i32>, d: i32) -> i64 {
        self.count = 0;
        let n = a.len();
        
        // Create difference array
        let mut c: Vec<i32> = a.iter()
            .zip(b.iter())
            .map(|(x, y)| x - y)
            .collect();
        
        if n > 0 {
            self.merge_sort(&mut c, 0, n - 1, d);
        }
        
        self.count
    }
}

fn main() {
    let mut sol = Solution::new();
    let nums1 = vec![3, -1];
    let nums2 = vec![-2, 2];
    let diff = -1;
    
    let result = sol.number_of_pairs(nums1, nums2, diff);
    println!("{}", result);
}