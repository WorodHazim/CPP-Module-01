/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wuabdull <wuabdull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 02:07:27 by wuabdull          #+#    #+#             */
/*   Updated: 2026/02/24 02:07:28 by wuabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

static std::string replace_all(const std::string &src,
                               const std::string &s1,
                               const std::string &s2)
{
    std::string out;
    std::string::size_type pos = 0;

    while (true)
    {
        std::string::size_type found = src.find(s1, pos);
        if (found == std::string::npos)
        {
            out.append(src, pos, std::string::npos);
            break;
        }

        out.append(src, pos, found - pos); 
        out.append(s2);                   
        pos = found + s1.length(); 
    }
    return out;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: invalid input" << std::endl;
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: cannot replace empty text" << std::endl;
        return 1;
    }

    std::ifstream in(filename.c_str());
    if (!in.is_open())
    {
        std::cerr << "Error: cannot open file" << std::endl;
        return 1;
    }

    std::string outName = filename + ".replace";
    std::ofstream out(outName.c_str());
    if (!out.is_open())
    {
        std::cerr << "Error: cannot open new file" << std::endl;
        return 1;
    }
    std::string content;
    char c;
    while (in.get(c))
         content += c;
    std::string result = replace_all(content, s1, s2);

    out << result;

    in.close();
    out.close();
    return 0;
}
