class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size() ;
        int l2 = nums2.size() ;
        if(l2 == 0){
            if(l1!=0){
                if(l1%2==0){
                    return (double)(nums1[l1/2]+nums1[l1/2-1])/2 ;
                }else{
                    return (double)nums1[l1/2] ;
                }
            }
        }else{
            if(l1==0){
                if(l2%2==0){
                    return (double)(nums2[l2/2]+nums2[l2/2-1])/2 ;
                }else{
                    return (double)nums2[l2/2] ;
                }
            }
        }
        int c = (l1+l2-1)/2 ;
        if(l1 == 1 && l2==1)
            return (double)(nums1[0]+nums2[0])/2 ;
        //search in nums1 ;
        int lmedian = 0 ;
		int lmid = 0 ;
        int l, h ;
        l = 0 ;
        h = l1-1 ;
        bool f = false ;
        while(l<=h){
            int m = (l+h)/2 ;
            //nums2中nums[1]小的数需要等于c-m个
            if(c-m <= 0){
                //c-m=0 即nums1[m]<=nums2[0]
                if(c-m == 0 && nums1[m] <= nums2[c-m]){
                    lmedian = nums1[m] ;
                    lmid = m ;
                    f= true ;
                    break ;
                }else{
                    h = m-1 ;
                }
            }else{
                if(c-m < l2){
                    if(nums1[m]>=nums2[c-m-1] && nums1[m]<=nums2[c-m]){
                        lmedian = nums1[m] ;
                        lmid = m ;
                        f = true ;
                        break ;
                    }else{
                        if(nums1[m]<nums2[c-m-1])
                            l = m+1 ;
                        else
                            h = m-1 ;
                    }
                }else{
                    if(c-m==l2){
                        if(nums1[m]>=nums2[c-m-1]){
                            lmedian = nums1[m] ;
                            lmid = m ;
                            f = true ;
                            break ;
                        }else{
                            l = m+1 ;
                        }
                    }else{
                        l = m+1 ;
                    }
                }
            }
        }
        if(!f){
            l = 0 ;
            h = l2-1 ;
            f = false ;
            while(l<=h){
                int m = (l+h)/2 ;
                if(c-m <= 0){
                //c-m=0 即nums1[m]<=nums2[0]
                    if(c-m == 0 && nums2[m] <= nums1[c-m]){
                        lmedian = nums2[m] ;
                        lmid = m ;
                        f= true ;
                        break ;
                    }else{
                        h = m-1 ;
                    }
                }else{
                    if(c-m < l1){
                        if(nums2[m]>=nums1[c-m-1] && nums2[m]<=nums1[c-m]){
                            lmedian = nums2[m] ;
                            lmid = m ;
                            f = true ;
                            break ;
                        }else{
                            if(nums2[m]<nums1[c-m-1])
                                l = m+1 ;
                            else
                                h = m-1 ;
                        }
                    }else{
                        if(c-m==l1){
                            if(nums2[m]>=nums1[c-m-1]){
                                lmedian = nums2[m] ;
                                lmid = m ;
                                f = true ;
                                break ;
                            }else{
                                l = m+1 ;
                            }
                        }else{
                            l = m+1 ;
                        }
                    }
                }
            }
            //cout << "Array2 " << lmid << " , " << lmedian << endl ;
			if((l1+l2)%2!=0){
				return (double)lmedian ;
			}else{
				if(lmid == l2-1 || (lmid <l2-1 && c-lmid<l1 && nums2[lmid+1]>nums1[c-lmid])){
					return (double)(lmedian+nums1[c-lmid])/2 ;
				}else{
					return (double)(lmedian+nums2[lmid+1])/2 ;
				}
			}
        }else{
            //cout << "Array1 " << lmid << " ," << lmedian << endl ;
			if((l1+l2)%2!=0){
				return (double)lmedian ;
			}else{
				if(lmid == l1-1 || (lmid <l1-1 && c-lmid<l2 && nums1[lmid+1]>nums2[c-lmid])){
					return (double)(lmedian+nums2[c-lmid])/2 ;
				}else{
					return (double)(lmedian+nums1[lmid+1])/2 ;
				}
			}
		}
		
    }
};