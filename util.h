
#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <algorithm>
class Util
{
public:
    static std::string vector_to_string(std::vector<std::string> vector)
    {
        std::string result = "";
        for (std::string value : vector)
        {
            result += ("'" + value + "', ");
        }
        return result;
    };

    static std::vector<int> create_range_vector(int start, int end, int stop = 1)
    {
        std::vector<int> range_vector;
        for (int current_val = start; current_val < end; current_val += stop)
        {
            range_vector.push_back(current_val);
        }

        return range_vector;
    }
    template <typename T>
    static bool is_two_vectors_equal(std::vector<T> vector_x, std::vector<T> vector_y)
    {
        if (vector_x.size() != vector_y.size())
        {
            return false;
        }

        for (int idx = 0; idx < vector_x.size(); idx++)
        {
            if (vector_x[idx] != vector_y[idx])
            {
                return false;
            }
        }
        return true;
    }

    static long int generate_random_number_within_bound(int inclusive_upper_bound)
    {
        std::random_device random_device;

        long int random_number = (random_device() % inclusive_upper_bound) + 1;

        return random_number;
    }

    template <typename T>
    static void shuffle_vector(std::vector<T> &vector)
    {
        // std::shuffle(vector.begin(), vector.end(), std::random_device{});
        int final_idx = vector.size() - 1;
        for (int _ = 0; _ < vector.size(); _ += 1)
        {
            int random_idx = Util::generate_random_number_within_bound(vector.size() - 2);
            Util::swap(vector, random_idx, final_idx);
        }
    }

    template <typename T>
    static void swap(std::vector<T> &vector, int idx_x, int idx_y)
    {
        T temp_val = vector.at(idx_x);
        vector[idx_x] = vector[idx_y];
        vector[idx_y] = temp_val;
    }

    template <typename T>
    static int find_index(std::vector<T> vector, T item)
    {

        for (int idx = 0; idx < vector.size(); idx++)
        {
            T current_item = vector.at(idx);
            if (current_item == item)
            {
                return idx;
            }
        }
        return -1; // if -1, not found
    }
    // ----------------------------Template------------------------------------
    template <typename T>
    static void print_vector(std::vector<T> vector)
    {
        for (T value : vector)
        {
            std::cout << value << "\t";
        }

        std::cout << std::endl;
    };

    template <typename T>
    static std::vector<T> vector_slice(std::vector<T> vector, int begin_idx, int exclusive_end_idx)
    {
        std::vector<T> vector_sliced;
        for (int idx = begin_idx; idx < exclusive_end_idx; idx++)
        {
            T val = vector.at(idx);
            vector_sliced.push_back(val);
        }

        return vector_sliced;
    };

    template <typename KeyType>
    static std::map<KeyType, int> count(std::vector<KeyType> vector)
    {
        std::map<KeyType, int> count_map;
        for (const KeyType value : vector)
        {
            if (!count_map.count(value))
            {
                count_map[value] = 0;
            }
            count_map[value] += 1;
        }
        return count_map;
    }
    template <typename KeyType, typename ValueType>
    static void print_map(std::map<KeyType, ValueType> map)
    {
        std::cout << "{" << std::endl;
        for (const auto &[key, value] : map)
        {
            std::cout << "  " << key << " : " << value << std::endl;
        }
        std::cout << "}" << std::endl;
    }
};

#endif
